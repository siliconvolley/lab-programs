
# Create a file
file.create("D:/AEC_File1.txt")
# Writing into a file
write.table(x = iris[1:10, ], file = "AEC_File1.txt")
# Reading a text file
myData = read.table(file = "AEC_File1.txt ")
print(myData)
# Renaming a file
file.rename("AEC_File1.txt", "AEC_renamed.txt")
# Listing the table
list.files()
# Copy a file
file.copy("D:/AEC_File1.txt", "D:/programs")
list.files("D:/programs")
