# Sample data
x = c(34, 42, 69,87, 90, 88) #X-Axis
y = c(1, 5, 14, 16, 19, 23) #Y-Axis

# Scatter Plot
plot(x, y, type = "p", 
     col = "red", pch = 16, 
     xlab = "X-Axis", ylab = "Y-Axis", main = "ScatterPlot Graph Example:")

# Line Plot
plot(x, y, type = "l", 
     col = "blue", lwd = 1, 
     xlab = "X-Axis", ylab = "Y-Axis", main = "Line Plot Graph Example:")

# Bar Plot
barplot(y, names.arg = x, 
        col = "green", 
        xlab = "X-Axis", ylab = "Y-Axis", main = "Bar Plot GraphExample: ")

# Histogram
hist(y, col = c("purple", "yellow", 'red', 'black', 'green'), 
     xlab = "X-Axis", ylab = "Frequency", main = "Histogram Graph Example:")
