# For 2 Water Jugs
from collections import deque

def water_jug_bfs(capacity_x, capacity_y, target):
    visited = set()
    queue = deque([(0, 0)])

    while queue:
        current_state = queue.popleft()
        x, y = current_state

        if current_state in visited:
            continue

        visited.add(current_state)

        if x == target or y == target:
            return True

        # Fill jug x
        queue.append((capacity_x, y))
        # Fill jug y
        queue.append((x, capacity_y))
        # Empty jug x
        queue.append((0, y))
        # Empty jug y
        queue.append((x, 0))
        # Pour water from jug x to jug y
        pour_amount = min(x, capacity_y - y)
        queue.append((x - pour_amount, y + pour_amount))
        # Pour water from jug y to jug x
        pour_amount = min(y, capacity_x - x)
        queue.append((x + pour_amount, y - pour_amount))

    return False

def water_jug_dfs(capacity_x, capacity_y, target, visited):
    if (0, 0) in visited:
        return False

    visited.add((0, 0))

    if capacity_x == target or capacity_y == target:
        return True

    return (
        water_jug_dfs(capacity_x, 0, target, visited) or
        water_jug_dfs(0, capacity_y, target, visited) or
        water_jug_dfs(capacity_x, capacity_y, target, visited) or
        water_jug_dfs(0, 0, target, visited) or
        water_jug_dfs(min(capacity_x, capacity_y), capacity_y - min(capacity_x, capacity_y), target, visited) or
        water_jug_dfs(capacity_x - min(capacity_x, capacity_y), min(capacity_x, capacity_y), target, visited)
    )

# Example usage
capacity_x = 4
capacity_y = 3
target = 2

print("BFS:", water_jug_bfs(capacity_x, capacity_y, target))
print("DFS:", water_jug_dfs(capacity_x, capacity_y, target, set()))
