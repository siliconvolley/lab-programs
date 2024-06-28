'''
 5) Given the following short movie reviews, each labeled with a genre, either comedy or
    action:
        a) fun, couple, love, love : comedy
        b) fast, furious, shoot : action
        c) couple, fly, fast, fun, fun :comedy
        d) furious, shoot, shoot, fun :action
        e) fly, fast, shoot, love :action
    and a new document D: fast, couple, shoot, fly
    compute the most likely class for D. Assume a naive Bayes classifier and use add-1
    smoothing for the likelihoods.
'''

# Import required libraries
from collections import defaultdict
import math

# Training data
data = [
    ("fun, couple, love, love", "comedy"),
    ("fast, furious, shoot", "action"),
    ("couple, fly, fast, fun, fun", "comedy"),
    ("furious, shoot, shoot, fun", "action"),
    ("fly, fast, shoot, love", "action")
]

# New document
D = "fast, couple, shoot, fly"

# Tokenizes a document by splitting it into words.
def tokenize(document):
    return document.split(", ")

# Trains a naive Bayes classifier on the given data.
def train_naive_bayes(data):
    word_counts = defaultdict(lambda: defaultdict(int))
    class_counts = defaultdict(int)
    total_documents = len(data)

    for document, cls in data:
        class_counts[cls] += 1
        words = tokenize(document)
        for word in words:
            word_counts[cls][word] += 1

    vocabulary = set(word for document, _ in data for word in tokenize(document))
    vocab_size = len(vocabulary)

    # Calculate prior probabilities
    priors = {cls: count / total_documents for cls, count in class_counts.items()}

    # Calculate likelihoods with add-1 smoothing
    likelihoods = defaultdict(lambda: defaultdict(float))
    for cls in word_counts:
        total_words_in_class = sum(word_counts[cls].values())
        for word in vocabulary:
            likelihoods[cls][word] = (word_counts[cls][word] + 1) / (total_words_in_class + vocab_size)
    
    return priors, likelihoods, vocabulary

# Classifies a document using the given priors, likelihoods, and vocabulary.
def classify(document, priors, likelihoods, vocabulary):
    words = tokenize(document)
    class_scores = defaultdict(float)

    for cls in priors:
        class_scores[cls] = math.log(priors[cls])
        for word in words:
            if word in vocabulary:
                class_scores[cls] += math.log(likelihoods[cls][word])
            else:
                # For words not in the vocabulary, use add-1 smoothing probability
                total_words_in_class = sum(likelihoods[cls].values())
                class_scores[cls] += math.log(1 / (total_words_in_class + len(vocabulary)))

    return max(class_scores, key=class_scores.get)

def main():
    priors, likelihoods, vocabulary = train_naive_bayes(data)
    result = classify(D, priors, likelihoods, vocabulary)
    print(f"The most likely class for the document '{D}' is: {result}")


if __name__ == "__main__":
    main()
    