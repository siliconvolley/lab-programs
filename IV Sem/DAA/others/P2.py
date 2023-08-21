class Job:
    def __init__(self, taskId, deadline, profit):
        self.taskId = taskId
        self.deadline = deadline
        self.profit = profit
    
def scheduleJobs(jobs, T):
    profit = 0
    slot = [-1] * T
    jobs.sort(key=lambda x: x.profit, reverse=True)
    for job in jobs:
        for j in reversed(range(job.deadline)):
            if j < T and slot[j] == -1:
                slot[j] = job.taskId
                profit += job.profit
                break
    print('The scheduled jobs are:', list(filter(lambda x: x != -1, slot)))
    print('The total profit earned is:', profit)
    
if __name__ == '__main__':
    jobs = []
    n = int(input('Enter the number of jobs: '))
    for i in range(n):
        taskId = int(input(f'Enter the task ID for job {i+1}: '))
        deadline = int(input(f'Enter the deadline for job {i+1}: '))
        profit = int(input(f'Enter the profit for job {i+1}: '))
        jobs.append(Job(taskId, deadline, profit))
    T = int(input('Enter the deadline limit: '))
    scheduleJobs(jobs, T)
