// 3) a) Implement rule-based tagger for the given corpus of sentences

#include <iostream>
#include <string>
#include <cstring>
#include <cctype>

using namespace std;

// Define arrays for different types of words
string nouns[] = {"cat", "mat", "bat", "rat", "dad", "well"};
string verbs[] = {"sit", "sat", "run", "ran"};
string dets[] = {"a", "an", "the", "this"};
string adverb[] = {"quickly", "wisely", "very"};
string prep[] = {"on", "at", "in", "from", "is"};

// Function to determine the part-of-speech tag for a word
void getTag(char word[], char tag[]) {
    int len = strlen(word);
    // Check if the word is a noun
    for (const string &noun : nouns) {
        if (strcmp(word, noun.c_str()) == 0) {
            strcpy(tag, "NN");
            return;
        }
    }
    // Check if the word is a preposition
    for (const string &prp : prep) {
        if (strcmp(word, prp.c_str()) == 0) {
            strcpy(tag, "PRP");
            return;
        }
    }
    // Check if the word is a verb
    for (const string &verb : verbs) {
        if (strcmp(word, verb.c_str()) == 0) {
            strcpy(tag, "VB");
            return;
        }
    }
    // Check if the word is a determiner
    for (const string &det : dets) {
        if (strcmp(word, det.c_str()) == 0) {
            strcpy(tag, "DET");
            return;
        }
    }
    // Check if the word is an adverb
    for (const string &det : adverb) {
        if (strcmp(word, det.c_str()) == 0) {
            strcpy(tag, "JJ");
            return;
        }
    }
    // Check for some common word endings to determine the part of speech
    if (len >= 3 && strcmp(&word[len - 3], "ing") == 0) {
        strcpy(tag, "VBG");
    } else if (len >= 2 && strcmp(&word[len - 2], "ed") == 0) {
        strcpy(tag, "VBD");
    } else if (len >=1 && strcmp(&word[len - 1], "s") == 0) {
        strcpy(tag, "NNS");
    } else if (len >= 2 && strcmp(&word[len - 2], "ly") == 0) {
        strcpy(tag, "RB");
    } else if (len >= 4 && strcmp(&word[len - 4], "able") == 0) {
        strcpy(tag, "JJ");
    } else   
        strcpy(tag, "NN");
}

// Function to convert a string to lowercase
void toLowerCase(char *str) {
    for (int i = 0; str[i]; i++) {
        str[i] = tolower(str[i]);
    }
}

int main() {
    char sentence[] = "Rishabh was pushing a guy";
    char taggedSentence[1000] = "";
    char word[50];
    char tag[10];
    char *token = strtok(sentence, " .");

    while (token != NULL) {
        strcpy(word, token); // Copy the token into word
        toLowerCase(word); // Convert the word to lowercase
        getTag(word, tag); // Determine the part of speech tag for the word
        
        char taggedWord[60]; // Buffer to hold tagged word
        int bufferSize = sizeof(taggedWord) + 1; // Calculate buffer size for snprintf

        // Format the word with its tag and append it to the tagged sentence
        snprintf(taggedWord, bufferSize, "%s/%s ", word, tag);

        // Check if appending the tagged word exceeds the buffer size
        if (strlen(taggedSentence) + strlen(taggedWord) < sizeof(taggedSentence)) {
            strcat(taggedSentence, taggedWord); // Append the tagged word to the tagged sentence
        } else {
            cout << "Tagged sentence exceeds buffer size." << endl; // Print error message if buffer overflow
            return 1; // Return 1 to indicate failure
        }
        token = strtok(NULL, " ."); // Get the next token
    }

    cout << "Tagged Sentence:\n" << taggedSentence << endl; // Print the tagged sentence

    return 0; // End the program
}
