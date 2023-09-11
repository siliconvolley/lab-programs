# data = c(23, 56, 20, 63)
x <- readline("x (comma separated): ") 
data <- as.numeric(strsplit(x, ",")[[1]]) 
print(data)
#places = c("Mulky","Mangalore","Udupi","Kumble")
places <- readline("Enter labels (comma-separated): ") 
labels <- (strsplit(places, ",")[[1]]) 
print(labels)

piepercent= round(100 * data / sum(data),1) 
symbol=paste(piepercent,"%")

pie(data, labels = symbol, main = "City pie chart", col = rainbow(length(data))) 
legend("topright", labels, cex=1, fill=rainbow(length(data))) 

library(plotrix) 
pie3D(data, labels = symbol, main = "City pie chart", col = rainbow(length(data))) 
legend("topright", labels, cex = 1, fill=rainbow(length(data)))