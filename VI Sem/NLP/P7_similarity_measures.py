'''
 7) The dataset contains following 4 documents.
        D1: " It is going to rain today "
        D2: " Today Rama is not going outside to watch rain"
        D3: “I am going to watch the movie tomorrow with Rama"
        D4: “Tomorrow Rama is going to watch the rain at sea shore "
    Find the top two relevant documents for the query document with the content “Rama
    watching the rain " using the latent semantic space model.

    Use the following similarity measure and show the result analysis using bar chart.
        a) Euclidean distance
        b) Cosine similarity
        c) Jaccard similarity
        d) Dice Similarity Coefficient.
'''

import numpy as np
import pandas as pd
import matplotlib.pyplot as plt
from sklearn.feature_extraction.text import CountVectorizer, TfidfTransformer
from sklearn.metrics.pairwise import euclidean_distances, cosine_similarity
from scipy.spatial.distance import jaccard, dice
from sklearn.decomposition import TruncatedSVD

# Documents and query
documents = [
    "It is going to rain today",
    "Today Rama is not going outside to watch rain",
    "I am going to watch the movie tomorrow with Rama",
    "Tomorrow Rama is going to watch the rain at sea shore"
]
query = "Rama watching the rain"

# Preprocess documents and query
vectorizer = CountVectorizer()
X = vectorizer.fit_transform(documents + [query])
X_dense = X.toarray()

# Apply Latent Semantic Analysis (LSA)
svd = TruncatedSVD(n_components=2)
X_lsa = svd.fit_transform(X_dense)

# Extract transformed query vector
query_vector = X_lsa[-1]
doc_vectors = X_lsa[:-1]

# Function to calculate Jaccard similarity
def jaccard_similarity(x, y):
    intersection = np.sum(np.minimum(x, y))
    union = np.sum(np.maximum(x, y))
    return intersection / union

# Function to calculate Dice similarity
def dice_similarity(x, y):
    intersection = np.sum(np.minimum(x, y))
    return 2 * intersection / (np.sum(x) + np.sum(y))

# Calculate similarities
euclidean_dists = euclidean_distances(doc_vectors, query_vector.reshape(1, -1)).flatten()
cosine_sims = cosine_similarity(doc_vectors, query_vector.reshape(1, -1)).flatten()
jaccard_sims = np.array([jaccard_similarity(doc_vectors[i], query_vector) for i in range(len(documents))])
dice_sims = np.array([dice_similarity(doc_vectors[i], query_vector) for i in range(len(documents))])

# Normalize Jaccard and Dice similarities to be in the same range as others
jaccard_sims = 1 - jaccard_sims
dice_sims = 1 - dice_sims

# Combine results into a DataFrame
results = pd.DataFrame({
    'Document': [f'D{i+1}' for i in range(len(documents))],
    'Euclidean': euclidean_dists,
    'Cosine': cosine_sims,
    'Jaccard': jaccard_sims,
    'Dice': dice_sims
})

# Sort results for each similarity measure to find top 2 relevant documents
top_documents = {}
for measure in ['Euclidean', 'Cosine', 'Jaccard', 'Dice']:
    top_docs = results.sort_values(by=measure, ascending=(measure == 'Euclidean')).head(2)
    top_documents[measure] = top_docs['Document'].values

# Print top 2 documents for each similarity measure
for measure, docs in top_documents.items():
    print(f'Top 2 documents using {measure} similarity: {docs}')

# Plot the results
fig, axes = plt.subplots(2, 2, figsize=(15, 10))

for ax, measure in zip(axes.flatten(), ['Euclidean', 'Cosine', 'Jaccard', 'Dice']):
    ax.bar(results['Document'], results[measure])
    ax.set_title(f'{measure} Similarity')
    ax.set_xlabel('Documents')
    ax.set_ylabel('Similarity')

plt.tight_layout()
plt.show()
