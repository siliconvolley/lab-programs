# For 3 Water Jugs
from collections import deque

def water_jug_bfs(capacity_x, capacity_y, capacity_z, target):
    visited = set()
    queue = deque([(0, 0, 0)])

    while queue:
        current_state = queue.popleft()
        x, y, z = current_state

        if current_state in visited:
            continue

        visited.add(current_state)

        if x == target or y == target or z == target:
            return True

        # Fill jug x
        queue.append((capacity_x, y, z))
        # Fill jug y
        queue.append((x, capacity_y, z))
        # Fill jug z
        queue.append((x, y, capacity_z))
        # Empty jug x
        queue.append((0, y, z))
        # Empty jug y
        queue.append((x, 0, z))
        # Empty jug z
        queue.append((x, y, 0))
        # Pour water from jug x to jug y
        pour_amount = min(x, capacity_y - y)
        queue.append((x - pour_amount, y + pour_amount, z))
        # Pour water from jug x to jug z
        pour_amount = min(x, capacity_z - z)
        queue.append((x - pour_amount, y, z + pour_amount))
        # Pour water from jug y to jug x
        pour_amount = min(y, capacity_x - x)
        queue.append((x + pour_amount, y - pour_amount, z))
        # Pour water from jug y to jug z
        pour_amount = min(y, capacity_z - z)
        queue.append((x, y - pour_amount, z + pour_amount))
        # Pour water from jug z to jug x
        pour_amount = min(z, capacity_x - x)
        queue.append((x + pour_amount, y, z - pour_amount))
        # Pour water from jug z to jug y
        pour_amount = min(z, capacity_y - y)
        queue.append((x, y + pour_amount, z - pour_amount))

    return False

def water_jug_dfs(capacity_x, capacity_y, capacity_z, target, visited):
    if (0, 0, 0) in visited:
        return False

    visited.add((0, 0, 0))

    if capacity_x == target or capacity_y == target or capacity_z == target:
        return True

    return (
        water_jug_dfs(capacity_x, 0, 0, target, visited) or
        water_jug_dfs(0, capacity_y, 0, target, visited) or
        water_jug_dfs(0, 0, capacity_z, target, visited) or
        water_jug_dfs(capacity_x, capacity_y, 0, target, visited) or
        water_jug_dfs(capacity_x, 0, capacity_z, target, visited) or
        water_jug_dfs(0, capacity_y, capacity_z, target, visited) or
        water_jug_dfs(capacity_x, capacity_y, capacity_z, target, visited) or
        water_jug_dfs(0, 0, 0, target, visited) or
        water_jug_dfs(min(capacity_x, capacity_y), capacity_y - min(capacity_x, capacity_y), 0, target, visited) or
        water_jug_dfs(capacity_x - min(capacity_x, capacity_y), min(capacity_x, capacity_y), 0, target, visited) or
        water_jug_dfs(min(capacity_x, capacity_z), 0, capacity_z - min(capacity_x, capacity_z), target, visited) or
        water_jug_dfs(capacity_x - min(capacity_x, capacity_z), 0, min(capacity_x, capacity_z), target, visited) or
        water_jug_dfs(0, min(capacity_y, capacity_z), capacity_z - min(capacity_y, capacity_z), target, visited) or
        water_jug_dfs(0, capacity_y - min(capacity_y, capacity_z), min(capacity_y, capacity_z), target, visited) or
        water_jug_dfs(min(capacity_x, capacity_y, capacity_z), capacity_y - min(capacity_x, capacity_y, capacity_z),
                      min(capacity_x, capacity_y, capacity_z), target, visited)
    )

# Example usage with jug capacities 5, 3, and 2, and target amount 4
capacity_x = 12
capacity_y = 8
capacity_z = 5
target = 4

print("BFS:", water_jug_bfs(capacity_x, capacity_y, capacity_z, target))
print("DFS:", water_jug_dfs(capacity_x, capacity_y, capacity_z, target, set()))
