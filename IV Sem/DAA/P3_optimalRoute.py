def find_route(streets, money): 
    n = len(streets)     
    dp = [0] * (n + 1)     
    for i in range(1, n + 1):         
        if streets[i - 1] in money: 
            dp[i] = max(dp[i], dp[i - 1] + money[streets[i - 1]])             
            dp[i] = max(dp[i], dp[i - 1])         
            route = []     
            i = n 
    while i > 0: 
        if dp[i] != dp[i - 1]: 
            route.append(streets[i - 1])             
            i -= 1             
            route.reverse()     
    return route 
streets = ['a', 'b', 'c', 'd', 'e'] 
money = {'a': 1, 'b': 2, 'c': 3, 'd': 5, 'e': 4} 
perfect_route = find_route(streets, money) 
print("The perfect path is: ", perfect_route) 
 
