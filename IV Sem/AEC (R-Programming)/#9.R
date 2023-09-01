
library(lattice)

avg_mpg_by_cyl = tapply(mtcars$mpg, mtcars$cyl, mean)
bar_plot = barchart(avg_mpg_by_cyl, main = "Average MPG by Number of Cylinders",
                    xlab = "Cylinders", ylab = "Average MPG", col = "red")
print(bar_plot)

# Create a scatter plot of MPG vs Horsepower
scatter_plot = xyplot(mpg ~ hp, data = mtcars, pch = 16, col = "green", main = "Scatter Plot
of MPG vs. Horsepower", xlab = "Horsepower", ylab = "MPG")
print(scatter_plot)

# Create a histogram of MPG values
histogram_plot = histogram (~ mpg, data = mtcars, main = "Histogram of MPG", xlab =
                              "MPG", ylab = "Frequency", col = "blue")
print(histogram_plot)

# Create a density plot of MPG values
density_plot <- densityplot(~ mpg, data = mtcars, main = "Density Plot of MPG", xlab =
                              "MPG", ylab = "Density", col = "black")
print(density_plot)

