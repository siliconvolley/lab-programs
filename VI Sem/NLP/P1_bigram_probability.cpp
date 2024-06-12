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
    vector<string> tokens; // Initialize a vector to store the tokens
    stringstream ss(sentence); // Create a stringstream object from the sentence
    string word; // Declare a string to hold each word
    while (ss >> word) { // Extract words from the stringstream
        tokens.push_back(word); // Add each word to the tokens vector
    }
    return tokens; // Return the vector of tokens
}

// Function to calculate bigram probabilities and print them
double calculateBigramProbability(const vector<string>& corpus, const string& sentence) {
    map<pair<string, string>, int> bigramCounts; // Map to store bigram counts
    map<string, int> wordCounts; // Map to store word counts

    // Tokenize and count bigrams in the corpus
    for (const string& s : corpus) { // Loop through each sentence in the corpus
        vector<string> tokens = tokenize(s); // Tokenize the sentence
        for (size_t i = 0; i < tokens.size() - 1; ++i) { // Loop through tokens to count bigrams
            bigramCounts[make_pair(tokens[i], tokens[i + 1])]++; // Increment bigram count
            wordCounts[tokens[i]]++; // Increment word count
        }
        // Count the last word of each sentence
        wordCounts[tokens.back()]++; // Increment count for the last word
    }

    // Print all bigram probabilities
    cout << "\n Bigram Probabilities: \n" << endl; // Print header for bigram probabilities
    for (const auto& bigramCount : bigramCounts) { // Loop through each bigram count
        const auto& bigram = bigramCount.first; // Extract the bigram
        int count = bigramCount.second; // Get the count of the bigram
        double probability = static_cast<double>(count) / wordCounts[bigram.first]; // Calculate probability
        cout << "P(" << bigram.second << " | " << bigram.first << ") = " << probability << endl; // Print probability
    }

    // Calculate the probability of the target sentence
    vector<string> targetTokens = tokenize(sentence); // Tokenize the target sentence
    double probability = 1.0; // Initialize probability to 1
    for (size_t i = 0; i < targetTokens.size() - 1; ++i) { // Loop through tokens of the target sentence
        pair<string, string> bigram = make_pair(targetTokens[i], targetTokens[i + 1]); // Form a bigram
        if (bigramCounts.find(bigram) != bigramCounts.end()) { // Check if the bigram exists in the corpus
            probability *= static_cast<double>(bigramCounts[bigram]) / wordCounts[bigram.first]; // Multiply probability
        } else {
            // If the bigram does not exist in the corpus, return 0 probability
            return 0; // Return 0 if the bigram is not found
        }
    }

    return probability; // Return the calculated probability
}

int main() {
    vector<string> corpus = { // Initialize the corpus with sentences
        "There is a big garden",
        "Children play in a garden",
        "They play inside beautiful garden"
    };

    string sentence = "They play in a big garden"; // Target sentence for probability calculation

    double probability = calculateBigramProbability(corpus, sentence); // Calculate the bigram probability
    cout << "\n Probability of the sentence \"" << sentence << "\": " << probability << endl; // Print the probability

    return 0; // End the program
}
