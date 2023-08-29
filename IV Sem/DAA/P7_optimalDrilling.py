import itertools 
 
def calculate_distance(x1, y1, x2, y2): 
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5 
 
def calculate_total_distance(points_order, distances): 
    total_distance = sum(distances[point1][point2] for point1, point2 in zip(points_order, points_order[1:])) 
    return total_distance 
 
def find_optimal_drilling_time(points, toolbox_time): 
    num_points = len(points)     
    distances = [[calculate_distance(x1, y1, x2, y2) for x2, y2, _ in points] for x1, y1, _ in points] 
    optimal_drilling_time = float('inf') 
    for permutation in itertools.permutations(range(num_points)):         
        total_distance = calculate_total_distance(permutation, distances) 
        drilling_time = total_distance + (num_points - 1) * toolbox_time 
        optimal_drilling_time = min(optimal_drilling_time, drilling_time) 
    return optimal_drilling_time 
def main(): 
    points = [(0, 0, 1), (3, 0, 2), (0, 4, 1), (3, 4, 2)] 
    toolbox_time = 5     
    optimal_time = find_optimal_drilling_time(points, toolbox_time)     
    print("Optimal Drilling Time:", optimal_time) 
 
if __name__ == "__main__": 
    main() 
    