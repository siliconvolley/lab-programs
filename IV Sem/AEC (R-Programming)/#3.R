# Create two strings
str1 <- readline("Enter String 1: ")
str2 <- readline("Enter String 2: ")

# Concatenate two strings
result <- paste(str1, str2, sep = "-")
paste("Concatenated string is",result)

# Compare both strings
result = toupper(str1) == toupper(str2)
paste("Are both the strings the same? :",result)

# Reverse the string
text1 <- readline("Enter a string: ")
reversed_text1 = paste(rev(strsplit(text1, "")[[1]]), collapse = "")
cat("Reversed String:", reversed_text1, "\n")

# Check if a given string is a palindrome
text2 <- readline("Enter a string: ")
reversed_text2 = paste(rev(strsplit(text2, "")[[1]]), collapse = "")
if (text2 == reversed_text2) {
  cat("The string is a palindrome.\n")
} else {
  cat("The string is not a palindrome.\n")
}
