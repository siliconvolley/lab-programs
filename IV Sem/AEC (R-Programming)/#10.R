# Load the lattice package for advanced visualizations
library(lattice)
# Create numeric vectors 'a' and 'b'
a = 1:10
b = 1:15
# Generate a data frame with all combinations of 'a' and 'b'
eg =- expand.grid(x=a, y=b)
# Calculate a new variable 'z' based on the formula
eg$z = eg$x^2 + eg$x * eg$y
# Create a 3D wireframe plot to visualize 'z' vs 'x' and 'y'
wireframe(z ~ x+y, eg)
#Level plot
x = seq(-pi, pi, length.out = 100)
y = seq(-pi, pi, length.out = 100)
z = outer(x, y, function(x, y) sin(sqrt(x^2 + y^2)))
levelplot(z, xlab = "x", ylab = "y", main = "2D Sin Function")
