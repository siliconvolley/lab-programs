
# Importing the example data
examples <- read.csv("D:/example.csv")

# Taking the mean
mean_value <- mean(examples[, 1])
cat("Mean =", mean_value)

# Taking the median
median_value <- median(examples[, 1])
cat("Median =", median_value)

# Taking the variance
variance_value <- var(examples[, 1])
cat("Variance =", variance_value)

# Taking the standard deviation
sd_value <- variance_value^0.5
cat("Standard Deviation =", sd_value)

# Taking the range
range_value <- range(examples[, 1])
cat("Range =", range_value)

# Taking the quartile
quartiles <- quantile(examples[, 1])
cat("Quartiles =",quartiles)
