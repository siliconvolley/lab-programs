
library(lattice)

x = seq(-pi, pi, length.out = 100)
y = seq(-pi, pi, length.out = 100)

eg = expand.grid(x=x, y=y)

eg$z = eg$x^2 + eg$y^2

# Create a 3D wireframe plot to visualize 'z' vs 'x' and 'y'
wireframe(z ~ x+y, eg)

#Level plot
z = outer(x, y, function(x, y) sin(sqrt(x^2 + y^2)))
levelplot(z, xlab = "x", ylab = "y", main = "2D Sin Function")
