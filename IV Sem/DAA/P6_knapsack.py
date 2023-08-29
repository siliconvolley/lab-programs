def knapSack(W, wt, val, n): 
    if n == 0 or W == 0: 
        return 0     
    if wt[n - 1] > W: 
        return knapSack(W, wt, val, n - 1)     
    return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1)) 

profit = [60, 100, 120] 
weight = [10, 20, 30] 
print(f"Profit = {profit}")
print(f"Weight = {weight}")

n = len(profit) 
W = 10 
print(f"Knapsack Capacity = {W}")
print(knapSack(W, weight, profit, n)) 	 
