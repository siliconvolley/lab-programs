import matplotlib.pyplot as plt 
import time 
import random 
 
class TVChannel:     
    def __init__(self, name, viewers, viewing_time, rating): 
        self.name = name         
        self.viewers = viewers 
        self.viewing_time = viewing_time 
        self.rating = rating 
 
def create_channel(i): 
    return TVChannel(f"Channel {i}", random.randint(500, 2000000), 
random.randint(30, 180), rate_channel()) 
 
def rate_channel(): 
    viewers = random.randint(500, 2000000) 
    if viewers >= 1500000: 
        return 1     
    elif viewers >= 1000000: 
        return 2     
    elif viewers >= 500000: 
        return 3     
    elif viewers >= 300000: 
        return 4     
    elif viewers >= 100000: 
        return 5     
    else: 
        return 6 
 
def quick_sort(arr):     
    if len(arr) <= 1: 
        return arr     
    pivot = arr[0]     
    smaller = [x for x in arr[1:] if x <= pivot]     
    greater = [x for x in arr[1:] if x > pivot]     
    return quick_sort(smaller) + [pivot] + quick_sort(greater)  

def plot_sorting_algorithms():
    sorting_algorithms = ["Quick Sort", "Merge Sort"] 
    running_times = [] 
    data = [random.randint(1, 200000) for _ in range(1, 10000)] 
    
    for algorithm in sorting_algorithms: 
        start_time = time.time() 
        if algorithm == "Quick Sort":
            quick_sort(data) 
        elif algorithm == "Merge Sort": 
            merge_sort(data) 
        end_time =time.time() 
        running_times.append(end_time - start_time) 
    plt.bar(sorting_algorithms, running_times)
    plt.xlabel("Sorting Algorithms") 
    plt.ylabel("Running Time (seconds)") 
    plt.title("Running Time Of Sorting Algorithms") 
    plt.show() 

def merge_sort(nlist): 
    if len(nlist) <= 1: return nlist 
    mid = len(nlist) // 2 
    lefthalf = merge_sort(nlist[:mid]) 
    righthalf = merge_sort(nlist[mid:]) 

    i = j = k = 0 
    while i < len(lefthalf) and j < len(righthalf): 
        if lefthalf[i] < righthalf[j]: 
            nlist[k] = lefthalf[i] 
            i += 1 
        else: 
            nlist[k] = righthalf[j] 
            j += 1 
        k += 1
    nlist[k:] = lefthalf[i:] + righthalf[j:] 
    return nlist 

# Main function 
 
channels = [create_channel(i + 1) for i in range(10)] 
print("Channels created successfully!") 
for channel in channels: 
    print(f"{channel.name}:\n {channel.viewers} viewers, {channel.viewing_time} hours, Rank: {channel.rating}") 
plot_sorting_algorithms() 
 
