import matplotlib.pyplot as plt
import pandas as pd
import numpy as np

dataframe = pd.read_csv('V Sem\Maths for ML\data\SOCR-HeightWeight.csv')
X = np.array(dataframe["Height(Inches)"])
Y = np.array(dataframe["Weight(Pounds)"])
X_mean = np.mean(X)
Y_mean = np.mean(Y)
X_deviation = np.subtract(X, X_mean)
Y_deviation = np.subtract(Y, Y_mean)

m = np.dot(X_deviation, Y_deviation) / np.dot(X_deviation, X_deviation)
b = Y_mean - m * X_mean

plt.scatter(X, Y, label='Data Points')
plt.plot(X, m * X + b, color='red', label=f'Regression Line: y = {m:.2f}x + {b:.2f}')
plt.xlabel('Height')
plt.ylabel('Weight')
plt.title('Linear Regression')
plt.legend()

plt.show()
