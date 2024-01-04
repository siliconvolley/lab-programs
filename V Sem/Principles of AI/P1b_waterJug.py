# For 3 Water Jugs
from collections import deque

def water_jug_bfs(capacity_x, capacity_y, capacity_z, target):
    visited = set()
    queue = deque([(0, 0, 0, [])])

    while queue:
        current_state = queue.popleft()
        x, y, z, sequence = current_state

        if (x, y, z) in visited:
            continue

        visited.add((x, y, z))

        if x == target:
            return sequence + [(x, y, z)]

        # Fill jug x
        queue.append((capacity_x, y, z, sequence + [(x, y, z)]))
        # Fill jug y
        queue.append((x, capacity_y, z, sequence + [(x, y, z)]))
        # Fill jug z
        queue.append((x, y, capacity_z, sequence + [(x, y, z)]))
        # Empty jug x
        queue.append((0, y, z, sequence + [(x, y, z)]))
        # Empty jug y
        queue.append((x, 0, z, sequence + [(x, y, z)]))
        # Empty jug z
        queue.append((x, y, 0, sequence + [(x, y, z)]))
        # Pour water from jug x to jug y
        pour_amount = min(x, capacity_y - y)
        queue.append((x - pour_amount, y + pour_amount, z, sequence + [(x, y, z)]))
        # Pour water from jug y to jug x
        pour_amount = min(y, capacity_x - x)
        queue.append((x + pour_amount, y - pour_amount, z, sequence + [(x, y, z)]))
        # Pour water from jug x to jug z
        pour_amount = min(x, capacity_z - z)
        queue.append((x - pour_amount, y, z + pour_amount, sequence + [(x, y, z)]))
        # Pour water from jug z to jug x
        pour_amount = min(z, capacity_x - x)
        queue.append((x + pour_amount, y, z - pour_amount, sequence + [(x, y, z)]))
        # Pour water from jug y to jug z
        pour_amount = min(y, capacity_z - z)
        queue.append((x, y - pour_amount, z + pour_amount, sequence + [(x, y, z)]))
        # Pour water from jug z to jug y
        pour_amount = min(z, capacity_y - y)
        queue.append((x, y + pour_amount, z - pour_amount, sequence + [(x, y, z)]))

    return []

# Example usage
capacity_x = 12
capacity_y = 8
capacity_z = 5
target = 2

bfs_sequence = water_jug_bfs(capacity_x, capacity_y, capacity_z, target)

print("BFS Sequence:", bfs_sequence)
