#1a - 🍑
import matplotlib.pyplot as plt
from sklearn.linear_model import LinearRegression
import numpy as np
years = np.array([2013,2014,2015,2016,2017]).reshape(-1,1)
advertising = np.array([100000,120000,140000,160000,220000])
sales = np.array([100000,120000,140000,160000,220000])
model = LinearRegression()
model.fit(years,sales)
next_year = np.array([[2018]])
predicted_sales = model.predict(next_year)
print("Predicted sales for 2018 based on advertising expenditure: ", predicted_sales[0])
plt.figure(figsize=(8,6))
plt.scatter(years,sales,color="blue",label = "Actual data")
plt.plot(years,model.predict(years),color = "red", label = "Linear regression")
plt.scatter(next_year,predicted_sales,color="green",label = "Predicted Point")
plt.title("Linear Regression: Years vs. Sales")
plt.xlabel("Year")
plt.ylabel("Sales")
plt.legend()
plt.grid(True)
plt.show()