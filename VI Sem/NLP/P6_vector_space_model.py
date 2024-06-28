'''
 6) The dataset contains following 5 documents:
        D1: "Shipment of gold damaged in a fire"
        D2: "Delivery of silver arrived in a silver truck"
        D3: "Shipment of gold arrived in a truck"
        D4: “Purchased silver and gold arrived in a wooden truck”
        D5: “The arrival of gold and silver shipment is delayed.”
    Find the top two relevant documents for the query document with the content “gold
    silver truck " using the vector space model.

    Use the following similarity measure and analyze the result:
        a) Euclidean distance
        b) Manhattan distance
        c) Cosine similarity
'''

# Import required libraries
import numpy as np
from sklearn.feature_extraction.text import CountVectorizer
from sklearn.metrics.pairwise import euclidean_distances, manhattan_distances, cosine_similarity

# Dataset
documents = [
    "Shipment of gold damaged in a fire",
    "Delivery of silver arrived in a silver truck",
    "Shipment of gold arrived in a truck",
    "Purchased silver and gold arrived in a wooden truck",
    "The arrival of gold and silver shipment is delayed."
]

query = "gold silver truck"

# Vectorize the documents and query
def vectorize_docs_and_query(documents, query):
    vectorizer = CountVectorizer()
    X = vectorizer.fit_transform(documents + [query])
    return X.toarray(), vectorizer.get_feature_names_out()

# Calculate Euclidean distance
def euclidean_distance(X, query_vector):
    return euclidean_distances(X, query_vector.reshape(1, -1)).flatten()

# Calculate Manhattan distance
def manhattan_distance(X, query_vector):
    return manhattan_distances(X, query_vector.reshape(1, -1)).flatten()

# Calculate Cosine similarity
def cosine_similarity_measure(X, query_vector):
    return cosine_similarity(X, query_vector.reshape(1, -1)).flatten()

# Get top N documents based on the similarity measure
def get_top_n_documents(distances, n, reverse=False):
    return np.argsort(distances)[::-1][:n] if reverse else np.argsort(distances)[:n]

# Main function to find top 2 relevant documents using different measures
def main():
    X, feature_names = vectorize_docs_and_query(documents, query)
    query_vector = X[-1]
    X = X[:-1]
    
    print("Documents:")
    for i, document in enumerate(documents):
        print(f"{i + 1}: {document}")

    print("\nFeature names:\n", feature_names)

    # Euclidean distance
    euclidean_dist = euclidean_distance(X, query_vector)
    top_euclidean = get_top_n_documents(euclidean_dist, 2)
    print("\nTop 2 documents using Euclidean distance:", top_euclidean)

    # Manhattan distance
    manhattan_dist = manhattan_distance(X, query_vector)
    top_manhattan = get_top_n_documents(manhattan_dist, 2)
    print("Top 2 documents using Manhattan distance:", top_manhattan)

    # Cosine similarity
    cosine_sim = cosine_similarity_measure(X, query_vector)
    top_cosine = get_top_n_documents(cosine_sim, 2, reverse=True)
    print("Top 2 documents using Cosine similarity:", top_cosine)

if __name__ == "__main__":
    main()
