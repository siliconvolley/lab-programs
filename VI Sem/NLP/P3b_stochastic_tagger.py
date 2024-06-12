# 3) b) Implement a stochastic tagger for the given corpus of sentences

import nltk
from nltk.corpus import brown
from collections import defaultdict, Counter
import random

# Download NLTK resources if not already downloaded
# nltk.download('brown')
# nltk.download('universal_tagset')

# Function to tag a sentence based on word-tag probabilities
def tag_sentence(sentence, word_tag_probabilities):
    tagged_sentence = []  # Initialize list to hold tagged words
    words = nltk.word_tokenize(sentence)  # Tokenize the sentence into words
    for word in words:  # Iterate through each word in the sentence
        tag = get_tag(word, word_tag_probabilities)  # Get the tag for the word
        tagged_sentence.append(f"{word}/{tag}")  # Append word and its tag to the list
    return " ".join(tagged_sentence)  # Return the tagged sentence as a string

# Function to get the most probable tag for a word
def get_tag(word, word_tag_probabilities):
    word = word.lower()  # Convert word to lowercase
    if word in word_tag_probabilities:  # Check if word exists in the probabilities
        tags = word_tag_probabilities[word]  # Get the tag probabilities for the word
        tag = random.choices(list(tags.keys()), weights=tags.values(), k=1)[0]  # Choose a tag randomly based on probabilities
        return tag  # Return the chosen tag
    else:
        # If the word is unknown, assign a tag based on common patterns
        if len(word) >= 3 and word.endswith("ing"):
            return "VERB"
        elif len(word) >= 2 and word.endswith("ed"):
            return "VERB"
        elif len(word) >= 1 and word.endswith("s"):
            return "NOUN"
        elif len(word) >= 2 and word.endswith("ly"):
            return "ADV"
        elif len(word) >= 4 and word.endswith("able"):
            return "ADJ"
        else:
            return "NOUN"  # Default tag is NOUN for unknown words

def main():
    word_tag_pairs = brown.tagged_words(tagset='universal')  # Get tagged words from Brown corpus

    # Count frequencies of word-tag pairs
    word_tag_freq = defaultdict(Counter)
    for word, tag in word_tag_pairs:
        word_tag_freq[word.lower()][tag] += 1

    # Calculate probabilities of word-tag pairs
    word_tag_probabilities = defaultdict(dict)
    for word, tags in word_tag_freq.items():
        total_count = sum(tags.values())
        for tag, count in tags.items():
            word_tag_probabilities[word][tag] = count / total_count

    # Input sentence to be tagged
    sentence = "Aditya can swim through the vast ocean of the Pacific"
    tagged_sentence = tag_sentence(sentence, word_tag_probabilities)  # Tag the input sentence

    print("Tagged Sentence:")
    print(tagged_sentence)  # Print the tagged sentence

if __name__ == '__main__':
    main()  # Execute the main function if the script is run directly
