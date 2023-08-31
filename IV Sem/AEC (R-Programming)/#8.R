  # Load required libraries
  library(ggplot2)
  # Histogram
  # Sample data for Histogram
  data = data.frame(values = rnorm(1000))
  # Create a histogram
  ggplot(data, aes(x = values)) +
    geom_histogram(binwidth = 0.5, fill = "lightblue", color = "black") +
    labs(title = "Histogram", x = "Values", y = "Frequency") + theme_minimal()
  library(ggplot2)
  #Box plot
  # Sample data for box plot
  data = data.frame(group = rep(c("A", "B", "C"), each = 50), value = rnorm(150))
  # Create a box plot
  ggplot(data, aes(x = group, y = value, fill = group)) +
    geom_boxplot() + labs(title = "Box Plot", x = "Group", y = "Value") +
    theme_minimal()
  
