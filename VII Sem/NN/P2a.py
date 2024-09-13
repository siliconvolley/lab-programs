# Q: Design a single unit perceptron for classification of a linearly separable binary dataset without using pre-defined models. Use the Perceptron() from sklearn

import numpy as np
from sklearn.linear_model import Perceptron

import matplotlib.pyplot as plt

# Generate a simple linearly separable binary dataset
X = np.array([[2, 3], [4, 5], [5, 6], [6, 7], [1, 1], [2, 2], [3, 3], [4, 4]])
y = np.array([1, 1, 1, 1, 0, 0, 0, 0])

# Initialize the Perceptron
perceptron = Perceptron()

# Train the Perceptron
perceptron.fit(X, y)

# Plot the dataset and decision boundary
plt.scatter(X[:, 0], X[:, 1], c=y, cmap='bwr', edgecolor='k')
x_values = np.linspace(0, 7, 100)
y_values = -(perceptron.coef_[0][0] * x_values + perceptron.intercept_) / perceptron.coef_[0][1]
plt.plot(x_values, y_values, label='Decision Boundary')
plt.xlabel('Feature 1')
plt.ylabel('Feature 2')
plt.legend()
plt.show()