
library(plotrix)

marks <- c(100,89,90,85)
subjects <- c("EGDL","CPS","English","Electrical")

pie(marks, labels=marks, main="Subject Results in 1st SEM", col=c("red", "green", "blue", "purple"))

legend("topright", subjects, cex=1, fill=c("red", "green", "blue", "purple"))

pie3D(marks, labels=marks, main="Subject Results in 1st SEM", col=c("red", "green", "blue", "purple"),explode=0.15)

legend("bottom",subjects,cex=1,fill=c("red", "green", "blue", "purple")) 

