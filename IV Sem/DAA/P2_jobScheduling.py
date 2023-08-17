#To find the maximum duration of all the jobs
def find_max_duration(jobs):
    durations = [t[0] for t in jobs]
    return max(durations)


#To return a list of the profits in each job
def job_profits(jobs):
    profits = [p[1] for p in jobs]
    return profits


#To the find the combination of jobs with maximum profit
def max_profit_list(jobs, totalTime):
    max_duration = find_max_duration(jobs)

    sorted_list = sorted(job_profits(jobs), reverse=True)

    job_slots = []
    for i in range(0, max_duration):
        job_slots.append(sorted_list[i])
    return job_slots

jobs = []

for i in range (0, 4):
    jobsInfo = input()
    jobsInfo = tuple(int(a) for a in jobsInfo.split(","))
    jobs.append(jobsInfo)

totalTime = int(input("Enter Total Time: "))

profit_list = max_profit_list(jobs)
print("Maximum Profit:", sum(profit_list))
print("Maximum Profit List:", profit_list)
