def find_optimal_schedule(jobs): 
    total_time = total_profit = 0     
    schedule = []     
    for duration, profit in sorted(jobs, key=lambda x: x[1] / x[0], reverse=True):         
        if total_time + duration <= profit: 
            schedule.append((duration, profit))             
            total_time += duration             
            total_profit += profit 
    return schedule 
def display_schedule(schedule): 
    total_time = sum(duration for duration, _ in schedule)     
    total_profit = sum(profit for _, profit in schedule)     
    print("Optimal Schedule:")     
    for i, (duration, profit) in enumerate(schedule): 
        print(f"Job {i + 1}: Duration={duration}, Profit={profit}")     
        print(f"\nTotal Time: {total_time}\nTotal Profit: {total_profit}") 
 
# Example usage 
jobs = [(3, 5), (4, 6), (2, 2), (1, 8), (5, 10)]  # Format: (duration, profit) 
display_schedule(find_optimal_schedule(jobs)) 
