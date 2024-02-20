import pandas as pd
import numpy as np
from sklearn.decomposition import TruncatedSVD

# 1. Sample Data (Replace this with your actual data)
ratings_data = pd.DataFrame({
    'user_id': [1, 1, 2, 2, 3, 3, 3],
    'product_id': ['A', 'B', 'A', 'C', 'A', 'B', 'C'],
    'rating': [5, 3, 4, 5, 2, 1, 4]
})

# 2. Create a Pivot Table 
ratings_matrix = ratings_data.pivot_table(index='user_id', columns='product_id', values='rating')

# 3. Handle Missing Values (if any)
ratings_matrix = ratings_matrix.fillna(0)  # Fill with zeros for simplicity

# 4. Perform SVD
svd = TruncatedSVD(n_components=2)  # Reduce to 2 latent factors 
decomposed_matrix = svd.fit_transform(ratings_matrix)

# 5. Interpretation

# Component contributions:
print("Variance explained by each component:")
print(svd.explained_variance_ratio_) 

# User factors:
print("\nUser representations in the latent space:")
print(decomposed_matrix) 

# Product factors:
print("\nProduct representations in the latent space:")
print(svd.components_) 