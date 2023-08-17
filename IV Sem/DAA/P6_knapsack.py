def knapsack_max_profit(weights, values, capacity):
    num_items = len(weights)
    
    dp = [[0] * (capacity + 1) for _ in range(num_items + 1)]
    
    for i in range(1, num_items + 1):
        for j in range(1, capacity + 1):
            if weights[i - 1] <= j:
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j])
            else:
                dp[i][j] = dp[i - 1][j]
    
    return dp[num_items][capacity]

weights = [2, 3, 4, 5]
values = [10, 20, 30, 40]
capacity = 10
max_profit = knapsack_max_profit(weights, values, capacity)
print("Maximum Profit:", max_profit)