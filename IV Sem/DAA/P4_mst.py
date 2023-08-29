import sys 
 
visited = [0 for i in range(0, 10)] 
n = int(input("Enter the number of nodes: ")) 
print("Enter the adjacency matrix: \n") 
cost = [] 
for i in range(0, n): 
    item = []     
    for j in range(0, n): 
        value = int(input()) 
        item.append(value)     
        cost.append(item) 
for item in cost:     
    for index, value in enumerate(item):         
        if value == 0: 
            item[index] = sys.maxsize 
visited[0] = 1 
ne = 1 
a = b = u = v = 0 
mincost = 0 
 
while ne < n: 
    minimum = sys.maxsize 
    for i in range(0, n): 
        if visited[i] != 0:             
            for j in range(0, n):                 
                if visited[j] == 0 and cost[i][j] < minimum: 
                    minimum = cost[i][j]                     
                    a = u = i 
                    b = v = j 
    if visited[u] == 0 or visited[v] == 0: 
        print(f"\nEdge {ne}:({a} {b}) cost: {minimum}")         
        ne += 1         
        mincost += minimum         
        visited[b] = 1     
        cost[a][b] = cost[b][a] = sys.maxsize 
print(f"\nMinimum cost = {mincost}") 
