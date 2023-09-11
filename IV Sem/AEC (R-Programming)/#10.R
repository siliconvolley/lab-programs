
library(lattice)

x_start <- as.numeric(readline("Enter starting value for x:"))
x_end <- as.numeric(readline("Enter ending value for x:"))
y_start <- as.numeric(readline("Enter starting value for y:"))
y_end <- as.numeric(readline("Enter ending value for y:"))

x <- x_start: x_end
y <- y_start: y_end

eg = -expand.grid(x=x, y=y)

eg$z = eg$x^2 + eg$x * eg$y

# Create a 3D wire-frame plot to visualize 'z' vs 'x' and 'y'
wireframe(z ~ x+y, eg)

#Level plot
x = seq(-pi, pi, length.out = 100)
y = seq(-pi, pi, length.out = 100)
z = outer(x, y, function(x, y) sin(sqrt(x^2 + y^2)))
levelplot(z, xlab = "x", ylab = "y", main = "2D Sin Function")
