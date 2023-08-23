def knapsack_max_profit(weights, costs, capacity):
    num_items = len(weights)

    # Create a table to store the maximum profits for different capacities
    table = [[0] * (capacity + 1) for _ in range(num_items + 1)]

    # Fill in the table using dynamic programming
    for i in range(1, num_items + 1):
        for j in range(1, capacity + 1):
            # If the current item's weight is less than or equal to the current capacity
            if weights[i - 1] <= j:
                # Consider the maximum profit by either including or excluding the current item
                table[i][j] = max(costs[i - 1] + table[i - 1][j - weights[i - 1]], table[i - 1][j])
            else:
                # If the current item's weight is greater than the current capacity, exclude it
                table[i][j] = table[i - 1][j]

    # Trace back through the table to find the items that contribute to the maximum profit
    selected_items = []
    total_weight = capacity
    for i in range(num_items, 0, -1):
        if table[i][total_weight] != table[i - 1][total_weight]:
            selected_items.append(i - 1)
            total_weight -= weights[i - 1]

    # Return the maximum profit and the selected items
    return table[num_items][capacity], selected_items

# Example usage:
weights = [2, 3, 4, 5]  # weights of the coffee bean types
costs = [10, 20, 30, 40]  # costs of the coffee bean types
capacity = 10  # maximum weight capacity of the bag

max_profit, selected_items = knapsack_max_profit(weights, costs, capacity)

print("Maximum Profit:", max_profit)
print("Selected Coffee Beans (index):", selected_items)
print("Selected Coffee Beans (weight):", [weights[i] for i in selected_items])
print("Selected Coffee Beans (cost):", [costs[i] for i in selected_items])