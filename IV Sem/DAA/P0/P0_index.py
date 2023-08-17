array = []
size = int(input('Enter the number of array elements: '))

print('Enter the array elements: ')

for i in range (0, int(size)):
    element = int(input())
    array.append(element)

index = int(input('Enter the index: '))

if(index < 0 or index >= size):
    print('Index out of range!')
else:
    print('Element at',index,'is',array[index])