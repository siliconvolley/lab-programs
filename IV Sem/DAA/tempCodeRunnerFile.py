import itertools

def calculate_distance(x1, y1, x2, y2):
    return ((x1 - x2) ** 2 + (y1 - y2) ** 2) ** 0.5

def calculate_total_distance(points_order, distances):
    total_distance = 0
    num_points = len(points_order)
    for i in range(num_points - 1):
        point1 = points_order[i]
        point2 = points_order[i + 1]
        total_distance += distances[point1][point2]
    return total_distance

def find_optimal_drilling_time(points, toolbox_time):
    num_points = len(points)
    distances = [[0] * num_points for _ in range(num_points)]

    for i in range(num_points):
        x1, y1, d1 = points[i]
        for j in range(num_points):
            x2, y2, d2 = points[j]
            distances[i][j] = calculate_distance(x1, y1, x2, y2)

    point_permutations = list(itertools.permutations(range(num_points)))

    optimal_drilling_time = float('inf')

    for permutation in point_permutations:
        total_distance = calculate_total_distance(permutation, distances)
        drilling_time = total_distance + (num_points - 1) * toolbox_time
        if drilling_time < optimal_drilling_time:
            optimal_drilling_time = drilling_time
    
    return optimal_drilling_time

def main():
    points = [(0, 0, 1), (3, 0, 2), (0, 4, 1), (3, 4, 2)]
    toolbox_time = 5
    optimal_time = find_optimal_drilling_time(points, toolbox_time)
    print("Optimal Drilling Time:", optimal_time)

if __name__  == "__main__":
    main()