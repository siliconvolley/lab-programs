import matplotlib as mat

channelList = {}
channelViewersList = []

# Merge Sort Function
def mergeSort (channelViewerList):
    if len(channelViewersList) > 1:
 
         # Finding the mid of the channelViewersListay
        mid = len(channelViewersList)//2
 
        # Dividing the channelViewersListay elements
        L = channelViewersList[:mid]
 
        # Into 2 halves
        R = channelViewersList[mid:]
 
        # Sorting the first half
        mergeSort(L)
 
        # Sorting the second half
        mergeSort(R)
 
        i = j = k = 0
 
        # Copy data to temp channelViewersList L[] and R[]
        while i < len(L) and j < len(R):
            if L[i] <= R[j]:
                channelViewersList[k] = L[i]
                i += 1
            else:
                channelViewersList[k] = R[j]
                j += 1
            k += 1
 
        # Checking if any element was left
        while i < len(L):
            channelViewersList[k] = L[i]
            i += 1
            k += 1
 
        while j < len(R):
            channelViewersList[k] = R[j]
            j += 1
            k += 1
 
no_of_channels = int(input("Enter the number of Channels: "))

print("Enter",no_of_channels,"Channel names and their Number of Viewers: ")

for i in range (no_of_channels):
    channelName = input()
    channelViewers = int(input())
    channelViewersList.append(channelViewers)

    channelList[channelName] = channelViewers

mergeSort(channelViewersList)
print(len(channelViewersList))
print(channelViewersList)
