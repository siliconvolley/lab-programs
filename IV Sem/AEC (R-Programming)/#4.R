
text <- readline("Enter a string: ")

# nchar string function
paste("Length of",text,"is",nchar(text))

# toupper string function
paste("Upper Case of",text,"is",toupper(text))

# tolower string function
paste("Lower Case of",text,"is",tolower(text))

# substr string function
paste("Sub-string of",text,"is",sub <- substr(text, 5, 10))

# grep string function
paste("grep (hell) of",text,"is",grep("hell", text))

# paste string function
paste("Hello","Sahyadri", sep = "-")

# strsplit string function
strsplit(text, "o")

# sprintf string function
operand <- 8
sprintf("Square of %d is %d", operand, operand^2)

# cat string function
cat("cat string function is working!")

# sub string function
string <- "Apple is the best"
print(string)
sub("Apple", "Samsung", string)
