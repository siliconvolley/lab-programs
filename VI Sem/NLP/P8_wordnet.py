'''
 8) Extract Synonyms and Antonyms for a given word using WordNet.
'''

import nltk
from nltk.corpus import wordnet

# # Make sure you have the WordNet data downloaded
# nltk.download('wordnet')
# # Optional: For additional multilingual WordNet data
# nltk.download('omw-1.4')

def get_synonyms_antonyms(word):
    synonyms = set()
    antonyms = set()

    for synset in wordnet.synsets(word):
        for lemma in synset.lemmas():
            synonyms.add(lemma.name())
            if lemma.antonyms():
                for antonym in lemma.antonyms():
                    antonyms.add(antonym.name())

    return synonyms, antonyms

def main():
    word = input("Enter a word: ")
    synonyms, antonyms = get_synonyms_antonyms(word)

    print(f"Synonyms of {word}: {synonyms}")
    print(f"Antonyms of {word}: {antonyms}")

if __name__ == "__main__":
    main()
