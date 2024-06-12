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
    vector<string> tokens;
    stringstream ss(text);
    string token;
    while (getline(ss, token, delimiter)) {
        if (!token.empty()) {
            tokens.push_back(token);
        }
    }
    return tokens;
}

void laplaceSmoothing(const vector<string>& corpus) {
    map<string, int> wordCounts;
    map<pair<string, string>, int> bigramCounts;
    int vocabularySize = 0;

    // Tokenize and count
    for (const string& sentence : corpus) {
        vector<string> tokens = tokenize(sentence);
        for (size_t i = 0; i < tokens.size(); ++i) {
            wordCounts[tokens[i]]++;
            if (i < tokens.size() - 1) {
                bigramCounts[make_pair(tokens[i], tokens[i + 1])]++;
            }
        }
    }

    vocabularySize = wordCounts.size();

    // Calculate and print probabilities with Laplace smoothing
    cout << fixed << setprecision(4);
    cout << "\n Bigram Probabilities after Laplace Smoothing: \n" << endl;
    for (const auto& bigramCount : bigramCounts) {
        const auto& bigram = bigramCount.first;
        double count = bigramCount.second;
        double smoothedProbability = (count + 1) / (wordCounts[bigram.first] + vocabularySize);
        cout << "P(" << bigram.second << " | " << bigram.first << ") = " << smoothedProbability << endl;
    }

    cout << endl;
}

int main() {
    vector<string> corpus = {
        "There is a big garden",
        "Children play in a garden",
        "They play inside beautiful garden"
    };

    laplaceSmoothing(corpus);

    return 0;
}