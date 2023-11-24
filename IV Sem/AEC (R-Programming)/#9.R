
library(lattice)

avg_mpg_by_cyl = tapply(mtcars$mpg, mtcars$cyl, mean)
barchart(avg_mpg_by_cyl, main = "Average MPG by Number of Cylinders", xlab = "Cylinders", ylab = "Average MPG", col = c("red", "green", "blue"))

# Create a scatter plot of MPG vs Horsepower
xyplot(mpg ~ hp, data = mtcars, pch = 16, main = "Scatter Plot of MPG vs. Horsepower", xlab = "Horsepower", ylab = "MPG", col = c("red", "green", "blue"))

# Create a histogram of MPG values
histogram_plot = histogram (~ mpg, data = mtcars, main = "Histogram of MPG", xlab = "MPG", ylab = "Frequency", col = c("red", "blue", "green"))
print(histogram_plot)

# Create a density plot of MPG values
densityplot(~ mpg, data = mtcars, pch = 16, lwd = 4, main = "Density Plot of MPG", xlab = "MPG", ylab = "Density", col = "black")
