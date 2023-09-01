
library(ggplot2)

data(iris)

# Bar Plot
bar_plot = ggplot(iris, aes(x = Species)) + geom_bar(fill = "purple") + labs(title = "Bar Plot
of Iris Species", x = "Species", y = "Count")
print(bar_plot)

# Line Plot
line_plot = ggplot(iris, aes(x = Sepal.Length, y = Sepal.Width, color = Species)) +
  geom_line() + labs(title = "Line Plot of Sepal Length vs Sepal Width", x = "Sepal Length", y
                     = "Sepal Width")
print(line_plot)

# Scatter Plot
scatter_plot = ggplot(iris, aes(x = Petal.Length, y = Petal.Width, color = Species, shape =
                                  Species)) + geom_point(size = 3, alpha = 0.7) + labs(title = "Scatter Plot of Petal Length vs
    Petal Width", x = "Petal Length", y = "Petal Width") + 
    scale_color_manual(values = c("setosa" = "red", "versicolor" = "green", "virginica" = "blue")) +
    scale_shape_manual(values = c("setosa" = 18, "versicolor" = 19, "virginica" = 20))
  print(scatter_plot)
