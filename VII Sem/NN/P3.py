# Build a Deep Feed Forward ANN by implementing the Backpropagation algorithm and test the same using appropriate data sets. Use the number of hidden layers >= 4.

import numpy as np
from sklearn import datasets
from sklearn.model_selection import train_test_split
from sklearn.preprocessing import StandardScaler, OneHotEncoder

# Activation functions and derivatives
def sigmoid(x):
    return 1 / (1 + np.exp(-x))

def sigmoid_derivative(x):
    return x * (1 - x)

def softmax(x):
    exp_x = np.exp(x - np.max(x, axis=0, keepdims=True))
    return exp_x / np.sum(exp_x, axis=0, keepdims=True)

def relu(x):
    return np.maximum(0, x)

def relu_derivative(x):
    return np.where(x > 0, 1, 0)

# Loss function: Cross-Entropy Loss for multi-class classification
def cross_entropy_loss(y_true, y_pred):
    m = y_true.shape[1]
    return -np.sum(y_true * np.log(y_pred + 1e-9)) / m

# Initialize weights and biases
def initialize_parameters(layer_dims):
    np.random.seed(1)
    parameters = {}
    for i in range(1, len(layer_dims)):
        parameters['W' + str(i)] = np.random.randn(layer_dims[i], layer_dims[i - 1]) * 0.01
        parameters['b' + str(i)] = np.zeros((layer_dims[i], 1))
    return parameters

# Forward propagation
def forward_propagation(X, parameters):
    cache = {'A0': X}
    A = X
    L = len(parameters) // 2
    for i in range(1, L+1):
        Z = np.dot(parameters['W' + str(i)], A) + parameters['b' + str(i)]
        if i < L:
            A = relu(Z)
        else:
            A = softmax(Z)  # Use softmax in the output layer for multi-class classification
        cache['Z' + str(i)] = Z
        cache['A' + str(i)] = A
    return A, cache

# Backward propagation
def backward_propagation(Y, parameters, cache):
    gradients = {}
    L = len(parameters) // 2
    m = Y.shape[1]
    dA = cache['A' + str(L)] - Y  # Difference between prediction and true value for softmax output

    for i in reversed(range(1, L+1)):
        dZ = dA * sigmoid_derivative(cache['A' + str(i)]) if i == L else dA * relu_derivative(cache['Z' + str(i)])
        dW = np.dot(dZ, cache['A' + str(i-1)].T) / m
        db = np.sum(dZ, axis=1, keepdims=True) / m
        dA = np.dot(parameters['W' + str(i)].T, dZ)

        gradients['dW' + str(i)] = dW
        gradients['db' + str(i)] = db
    return gradients

# Update parameters using gradient descent
def update_parameters(parameters, gradients, learning_rate):
    L = len(parameters) // 2
    for i in range(1, L+1):
        parameters['W' + str(i)] -= learning_rate * gradients['dW' + str(i)]
        parameters['b' + str(i)] -= learning_rate * gradients['db' + str(i)]
    return parameters

# Training the neural network
def train(X, Y, layer_dims, learning_rate=0.01, epochs=1000):
    parameters = initialize_parameters(layer_dims)
    for epoch in range(epochs):
        A, cache = forward_propagation(X, parameters)
        cost = cross_entropy_loss(Y, A)
        gradients = backward_propagation(Y, parameters, cache)
        parameters = update_parameters(parameters, gradients, learning_rate)
       
        if epoch % 100 == 0:
            print(f"Epoch {epoch} - Loss: {cost:.4f}")
    return parameters

# Predict
def predict(X, parameters):
    A, _ = forward_propagation(X, parameters)
    predictions = np.argmax(A, axis=0)
    return predictions

# Load and prepare the Iris dataset
iris = datasets.load_iris()
X = iris.data.T  # Features (transpose to fit the model)
Y = iris.target.reshape(-1, 1)  # Labels

# One-hot encode the labels
encoder = OneHotEncoder(sparse=False)
Y = encoder.fit_transform(Y).T  # Convert to one-hot and transpose

# Normalize the features
scaler = StandardScaler()
X = scaler.fit_transform(X.T).T  # Transpose before and after scaling

# Split the data into training and testing sets
X_train, X_test, Y_train, Y_test = train_test_split(X.T, Y.T, test_size=0.2, random_state=42)
X_train, X_test = X_train.T, X_test.T  # Transpose back for our model
Y_train, Y_test = Y_train.T, Y_test.T

# Define the architecture of the neural network
layer_dims = [4, 6, 6, 6, 6, 3]  # 4 input features, 4 hidden layers with 6 neurons each, 3 output classes

# Train the model
parameters = train(X_train, Y_train, layer_dims, learning_rate=0.1, epochs=1000)

# Make predictions on the test set
predictions = predict(X_test, parameters)

# Convert one-hot encoded Y_test back to class labels for comparison
Y_test_labels = np.argmax(Y_test, axis=0)

# Print accuracy
accuracy = np.mean(predictions == Y_test_labels) * 100
print(f"Test Set Accuracy: {accuracy:.2f}%")