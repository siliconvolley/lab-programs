library(ggplot2)

ggplot(mtcars, aes(x=mpg)) + geom_histogram(binwidth = 1, col = "black", fill = "orangered")

ggplot (mtcars, aes(x=hp)) + geom_boxplot(col = "black", fill = "lightblue")

print(mtcars['hp'])
print(iris['Sepal'])
