import sys

class Graph:
    def _init_(self, num_vertices):
        self.num_vertices = num_vertices
        self.graph = [[0] * num_vertices for _ in range(num_vertices)]

    def add_edge(self, src, dest, weight):
        self.graph[src][dest] = weight
        self.graph[dest][src] = weight

    def print_mst(self, parent):
        print("Minimum Spanning Tree (MST):")
        total_cost = 0
        for v in range(1, self.num_vertices):
            print(f"Edge: {parent[v]} - {v}, Weight: {self.graph[v][parent[v]]}")
            total_cost += self.graph[v][parent[v]]
        print(f"Total Cost: {total_cost}")

    def find_min_key(self, key, mst_set):
        min_key = sys.maxsize
        min_index = -1
        for v in range(self.num_vertices):
            if key[v] < min_key and not mst_set[v]:
                min_key = key[v]
                min_index = v
        return min_index

    def prim_mst(self):
        key = [sys.maxsize] * self.num_vertices
        parent = [None] * self.num_vertices
        key[0] = 0
        mst_set = [False] * self.num_vertices
        parent[0] = -1
        for _ in range(self.num_vertices):
            u = self.find_min_key(key, mst_set)
            mst_set[u] = True
            for v in range(self.num_vertices):
                if self.graph[u][v] > 0 and not mst_set[v] and self.graph[u][v] < key[v]:
                    key[v] = self.graph[u][v]
                    parent[v] = u
        self.print_mst(parent)

g = Graph(5)

g.add_edge(0, 1, 2)
g.add_edge(0, 3, 6)
g.add_edge(1, 2, 3)
g.add_edge(1, 3, 8)
g.add_edge(1, 4, 5)
g.prim_mst()
