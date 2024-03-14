# For 2 Water Jugs
from collections import deque

def water_jug_bfs(capacity_x, capacity_y, target):
    visited = set()
    queue = deque([(0, 0, [])])

    while queue:
        current_state = queue.popleft()
        x, y, sequence = current_state

        if (x, y) in visited:
            continue

        visited.add((x, y))

        if x == target:
            return sequence + [(x, y)]

        # Fill jug x
        queue.append((capacity_x, y, sequence + [(x, y)]))
        # Fill jug y
        queue.append((x, capacity_y, sequence + [(x, y)]))
        # Empty jug x
        queue.append((0, y, sequence + [(x, y)]))
        # Empty jug y
        queue.append((x, 0, sequence + [(x, y)]))
        # Pour water from jug x to jug y
        pour_amount = min(x, capacity_y - y)
        queue.append((x - pour_amount, y + pour_amount, sequence + [(x, y)]))
        # Pour water from jug y to jug x
        pour_amount = min(y, capacity_x - x)
        queue.append((x + pour_amount, y - pour_amount, sequence + [(x, y)]))

    return []

# Example usage
capacity_x = 4
capacity_y = 3
target = 2

bfs_sequence = water_jug_bfs(capacity_x, capacity_y, target)

print("BFS Sequence:", bfs_sequence)
