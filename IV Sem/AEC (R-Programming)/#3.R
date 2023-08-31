# Create two strings
str1 = "Artificial"
str2 = "Intelligence"
# using paste() to concatenate two strings
result = paste(str1, str2)
print(result)
# Compare both strings
result = toupper(str1) == toupper(str2)
print(result)
# Reverse the string
text = "Maths is fun"
reversed_text = rev(strsplit(text, "")[[1]])
reversed_text = paste(reversed_text, collapse = "")
cat("Reversed String:", reversed_text, "\n")
# Check if a given string is a palindrome
text2 = "mom"
# Reverse the string
reversed_string = rev(strsplit(text2, "")[[1]])
reversed_string = paste(reversed_string, collapse = "")
# Check if the input string is equal to its reverse
if (text2 == reversed_string) {
  cat("The string is a palindrome.\n")
} else {
  cat("The string is not a palindrome.\n")
}
