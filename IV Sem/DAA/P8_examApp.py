from itertools import combinations 
 
def calculate_min_time_slots(subjects): 
    students = set(student for subject in subjects for student in subject)     
    graph = {student: set() for student in students} 
    for subjects_list in subjects:         
        for student1, student2 in combinations(subjects_list, 2): 
            graph[student1].add(student2) 
            graph[student2].add(student1) 
    def graph_coloring(): 
        color = {}         
        for student in graph:             
            neighbors_color = set(color.get(neighbor, None) for neighbor in graph[student])             
            for c in range(1, len(graph) + 1):                 
                if c not in neighbors_color: 
                    color[student] = c                     
                    break 
        return max(color.values()) 
 
    min_time_slots = graph_coloring() 
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
 
if __name__ == "__main__": 
    main() 

