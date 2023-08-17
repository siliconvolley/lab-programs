def tsp(graph, start):
    num_nodes = len(graph)
    visited = (1 << num_nodes) - 1 # Mark all nodes as unvisited except the starting node
    memo = {} # Memoization dictionary for storing subproblem solutions

    def tsp_util(curr_node, visited):
        if visited == 0: # Base case: All nodes have been visited
            return graph[curr_node][start] # Return to the starting node
        # Check if the subproblem has already been solved
        if (curr_node, visited) in memo:
            return memo[(curr_node, visited)]
            min_cost = sys.maxsize
        for next_node in range(num_nodes):
            if visited & (1 << next_node): # If the next node has not been visited
                cost = graph[curr_node][next_node] + tsp_util(next_node, visited & ~(1 << next_node))
            min_cost = min(min_cost, cost)
            memo[(curr_node, visited)] = min_cost # Memoize the subproblem solution
            return min_cost
        return tsp_util(start, visited)

def get_optimal_route(graph, start):
    num_nodes = len(graph)
    visited = (1 << num_nodes) - 1 # Mark all nodes as unvisited except the starting node
    memo = {} # Memoization dictionary for storing subproblem solutions

    def tsp_util(curr_node, visited):
        if visited == 0: # Base case: All nodes have been visited
            return [start]
        # Check if the subproblem has already been solved
        if (curr_node, visited) in memo:
            return memo[(curr_node, visited)]
            min_cost = sys.maxsize
        optimal_route = []
        for next_node in range(num_nodes):
            if visited & (1 << next_node): # If the next node has not been visited
                cost = graph[curr_node][next_node] + tsp_util(next_node, visited & ~(1 << next_node))
            if cost < min_cost:
                min_cost = cost
                optimal_route = [curr_node] + tsp_util(next_node, visited & ~(1 << next_node))
                memo[(curr_node, visited)] = optimal_route # Memoize the subproblem solution
                return optimal_route
        return tsp_util(start, visited)

# Example usage
graph = [
    [0, 10, 20, 30], # Cost matrix representing distances between nodes
    [10, 0, 5, 15],
    [20, 5, 0, 8],
    [30, 15, 8, 0]
]
start_node = 0 # Starting node index
optimal_route = get_optimal_route(graph, start_node)
total_cost = tsp(graph, start_node)
print("Optimal Route:")
for node in optimal_route:
    print(f"Node {node + 1}")
print(f"\nTotal Cost: {total_cost}")