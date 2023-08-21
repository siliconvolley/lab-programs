def dij(n, v, cost):
    flag = [0 for x in range(1, n + 2, 1)]
    
    dist = [float("inf") for x in range(1, n + 2, 1)]
    dist[v] = 0
    path = [[] for x in range(1, n + 2, 1)]
    path[v].append(v)
    
    for _ in range(1, n + 1, 1):
        u = -1
        min_dist = float("inf")
        for w in range(1, n + 1, 1):
            if not flag[w] and dist[w] < min_dist:
                u = w
                min_dist = dist[w]
        if u == -1:
            break
        flag[u] = 1
            
        for w in range(1, n + 1, 1):
            if dist[u] + cost[u][w] < dist[w]:
                dist[w] = dist[u] + cost[u][w]
                path[w] = path[u] + [w]
            
    return dist, path

n = int(input("Enter the number of vertices: "))
print("Enter the weighted matrix (seperated by spaces): ")
cost = [[0 for j in range(1, n + 2, 1)] for i in range(1, n + 2, 1)]
for i in range(1, n + 1, 1):
    row = list(map(int, input().split()))
    for j in range(1, n + 1, 1):
        cost[i][j] = row[j - 1]
        if cost[i][j] == 0:
            cost[i][j] = float("inf")
        
v = int(input("Enter the source vertex: "))
dist, path = dij(n, v, cost)
print("The shortest path from the source", v, "to the remaining vertices is: ")
for i in range(1, n + 1):
    if  i != v:
        print(v, "->", " -> ".join(map(str, path[i][1:])), "=", dist[i])