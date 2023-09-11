
library(ggplot2)

data = data.frame(values = rnorm(1000))

# Create a histogram
ggplot(data, aes(x = values)) + 
  geom_histogram(binwidth = 0.5, fill = "red", color = "blue") + 
  labs(title = "Histogram", x = "Values", y = "Frequency") + 
  theme_minimal()

data = data.frame(group = rep(c("A", "B", "C"), each = 50), value = rnorm(150))

# Create a box plot
ggplot(data, aes(x = group, y = value, fill = group)) + 
  geom_boxplot(fill = c("black", "yellow", "lavender")) + 
  labs(title = "Box Plot", x = "Group", y = "Value") + 
  theme_dark()
