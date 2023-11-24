
library(lattice)

data(mtcars)
barchart(mpg~factor(cyl),data=mtcars,main="Barplot",col="blue")

