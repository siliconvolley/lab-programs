import itertools

def euclidean_distance(point1, point2):
    return(((point1[0]-point2[0])**2 + (point1[1]-point2[1])**2)**0.5)

def total_distance(path, points):
    total = 0
    for i in range(len(path)-1):
        total += euclidean_distance(points[path[i]], points[path[i+1]])
        total += euclidean_distance(points[path[-1]], points[path[0]])
    return total

def optimal_drilling_order(points):
    num_points = len(points)
    points_indices=list(range(num_points))
    min_distance = float('inf')
    optimal_order = []

    for path in itertools.permutations(points_indices):
        distance = total_distance(path, points)
        if distance < min_distance:
            min_distance = distance
            optimal_order = path
    return optimal_order, min_distance

holes = [(0, 0, 1), (3, 0, 2), (0, 4, 1), (3, 4, 2)]
optimal_order, min_distance = optimal_drilling_order(holes)
print("Optimal Drilling Order: ", optimal_order)
print("Minimized Travel Time: ", min_distance)
