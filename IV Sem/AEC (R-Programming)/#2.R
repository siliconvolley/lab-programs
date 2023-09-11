# Create a file
file.create("D:/aec-programs/rishabh.txt")
list.files("D:/aec-programs/")

# Writing into a .txt file
text = "This is a test for writing into a file in R\n"
cat(text, file = "D:/aec-programs/rishabh.txt")
content <- readLines("D:/aec-programs/rishabh.txt")
print(content)

# Renaming a file
file.rename("D:/aec-programs/rishabh.txt", "D:/aec-programs/rishabh(changed).txt")

# Reading a file
text <- readLines("D:/aec-programs/rishabh(changed).txt")
print(text)

# Listing all the files
list.files() # Default directory
list.files("D:/aec-programs/") # My directory

# Copying a file
file.copy("D:/aec-programs/rishabh(changed).txt", "D:/aec-programs/rishabh(final).txt")
