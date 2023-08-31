marks<-c(100,65,89,90,85)
subjects<-c("Math","DAA","R","OS","ARM")

percentage<-round(100 * marks/sum(marks),1)

pie(marks, labels=marks, main="Marks scored by a student", col=rainbow(length(marks)))
legend("topleft",subjects,cex=1,fill =rainbow(length(marks)))

library(plotrix)

pie3D(marks, labels=marks, main="Marks scored by a person", col=rainbow(length(marks)),explode=0.2)
legend("bottom",subjects,cex=1,fill =rainbow(length(marks))) 

