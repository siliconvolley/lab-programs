graph = {
    '5': ['3', '7'],
    '3': ['2', '4'],
    '7': ['8'],
    '2': [],
    '4': ['8'],
    '8': []
}   # dictionary to represent a graph

visited = set() # set to represent the visited nodes (set to represent a stack)

def dfs(visited, graph, node):  # loop that iterates through the neighbours of the current node (node = 5, 3, 2, 4, 8, 7)
    if node not in visited: # to check whether the current neighbour has been visited or not
        print(node, end = " ")  # display the visited node
        visited.add(node) # add the current node to the visited list
        for neighbour in graph[node]:   # loop that iterates through the neighbours of the current node
            dfs(visited, graph, neighbour)  # calls itself by taking the current neighbour as the root node and continues the loop

print("DFS Algorithm: ")    
dfs(visited, graph, '5')    # calls the DFS function