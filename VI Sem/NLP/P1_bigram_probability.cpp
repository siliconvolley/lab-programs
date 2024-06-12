// 1) Consider the following Corpus of three sentences:
//      a) There is a big garden
//      b) Children play in a garden
//      c) They play inside beautiful garden
//    Calculate P for the sentence "They play in a big garden" assuming a bigram language model

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Function to tokenize a sentence into words
vector<string> tokenize(const string& sentence) {
    vector<string> tokens;
    stringstream ss(sentence);
    string word;
    while (ss >> word) {
        tokens.push_back(word);
    }
    return tokens;
}

// Function to calculate bigram probabilities and print them
double calculateBigramProbability(const vector<string>& corpus, const string& sentence) {
    map<pair<string, string>, int> bigramCounts;
    map<string, int> wordCounts;

    // Tokenize and count bigrams in the corpus
    for (const string& s : corpus) {
        vector<string> tokens = tokenize(s);
        for (size_t i = 0; i < tokens.size() - 1; ++i) {
            bigramCounts[make_pair(tokens[i], tokens[i + 1])]++;
            wordCounts[tokens[i]]++;
        }
        // Count the last word of each sentence
        wordCounts[tokens.back()]++;
    }

    // Print all bigram probabilities
    cout << "\n Bigram Probabilities: \n" << endl;
    for (const auto& bigramCount : bigramCounts) {
        const auto& bigram = bigramCount.first;
        int count = bigramCount.second;
        double probability = static_cast<double>(count) / wordCounts[bigram.first];
        cout << "P(" << bigram.second << " | " << bigram.first << ") = " << probability << endl;
    }

    // Calculate the probability of the target sentence
    vector<string> targetTokens = tokenize(sentence);
    double probability = 1.0;
    for (size_t i = 0; i < targetTokens.size() - 1; ++i) {
        pair<string, string> bigram = make_pair(targetTokens[i], targetTokens[i + 1]);
        if (bigramCounts.find(bigram) != bigramCounts.end()) {
            probability *= static_cast<double>(bigramCounts[bigram]) / wordCounts[bigram.first];
        } else {
            // If the bigram does not exist in the corpus, return 0 probability
            return 0;
        }
    }

    return probability;
}

int main() {
    vector<string> corpus = {
        "There is a big garden",
        "Children play in a garden",
        "They play inside beautiful garden"
    };

    string sentence = "They play in a big garden";

    double probability = calculateBigramProbability(corpus, sentence);
    cout << "\n Probability of the sentence \"" << sentence << "\": " << probability << endl;

    return 0;
}