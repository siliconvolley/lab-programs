// 2) Find the bigram count for the given Corpus Apply Laplace smoothing and
//    find the bigram probabilities after add one smoothing (up to 4 decimal places)

#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <iomanip>
#include <sstream>

using namespace std;

vector<string> tokenize(const string& text, char delimiter = ' ') {
    vector<string> tokens; // Initialize vector to store tokens
    stringstream ss(text); // Create stringstream from input text
    string token; // Declare string to hold each token
    while (getline(ss, token, delimiter)) { // Extract tokens using delimiter
        if (!token.empty()) { // Check if token is not empty
            tokens.push_back(token); // Add non-empty token to vector
        }
    }
    return tokens; // Return vector of tokens
}

void laplaceSmoothing(const vector<string>& corpus) {
    map<string, int> wordCounts; // Map to store word counts
    map<pair<string, string>, int> bigramCounts; // Map to store bigram counts
    int vocabularySize = 0; // Initialize vocabulary size

    // Tokenize and count
    for (const string& sentence : corpus) { // Loop through each sentence in the corpus
        vector<string> tokens = tokenize(sentence); // Tokenize the sentence
        for (size_t i = 0; i < tokens.size(); ++i) { // Loop through tokens
            wordCounts[tokens[i]]++; // Increment count for each word
            if (i < tokens.size() - 1) { // Check if there is another word for bigram
                bigramCounts[make_pair(tokens[i], tokens[i + 1])]++; // Increment bigram count
            }
        }
    }

    vocabularySize = wordCounts.size(); // Update vocabulary size

    // Calculate and print probabilities with Laplace smoothing
    cout << fixed << setprecision(4); // Set output format
    cout << "\n Bigram Probabilities after Laplace Smoothing: \n" << endl; // Print header
    for (const auto& bigramCount : bigramCounts) { // Loop through bigram counts
        const auto& bigram = bigramCount.first; // Extract bigram
        double count = bigramCount.second; // Get count of the bigram
        double smoothedProbability = (count + 1) / (wordCounts[bigram.first] + vocabularySize); // Calculate smoothed probability
        cout << "P(" << bigram.second << " | " << bigram.first << ") = " << smoothedProbability << endl; // Print probability
    }

    cout << endl; // Print an empty line for better readability
}

int main() {
    vector<string> corpus = { // Initialize the corpus with sentences
        "There is a big garden",
        "Children play in a garden",
        "They play inside beautiful garden"
    };

    laplaceSmoothing(corpus); // Apply Laplace smoothing to the corpus

    return 0; // End the program
}
