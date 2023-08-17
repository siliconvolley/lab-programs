from collections import defaultdict

class Graph:
    def _init_(self):
        self.graph = defaultdict(list)
    
    def add_edge(self, u, v):
        self.graph[u].append(v)
        self.graph[v].append(u)
    
    def is_safe(self, v, color, c):
        for neighbor in self.graph[v]:
            if color[neighbor] == c:
                return False
        return True
    
    def graph_coloring(self):
        num_vertices = len(self.graph)
        color = [-1] * num_vertices
        
        
        def assign_colors(v):
            if v == num_vertices:
                return True
            for c in range(1, num_vertices + 1):
                if self.is_safe(v, color, c):
                    color[v] = c
                    if assign_colors(v + 1):
                        return True
                    color[v] = -1
            return False
        
        assign_colors(0)
        return max(color)

def calculate_min_time_slots(subjects):
    graph = Graph()
    
    
    for i in range(len(subjects)):
        for j in range(i + 1, len(subjects)):
            if len(set(subjects[i]) & set(subjects[j])) > 0:
                graph.add_edge(i, j)
    
    min_time_slots = graph.graph_coloring()
    return min_time_slots

def main():
    
    subjects = [
        ["Alice", "Bob", "Charlie"],
        ["Bob", "David"],
        ["Charlie", "Eve", "Frank"],
        ["David", "Frank"]
    ]
    min_time_slots = calculate_min_time_slots(subjects)
    print("Minimum Time Slots:", min_time_slots)

if __name__ == "_main_":
    main()