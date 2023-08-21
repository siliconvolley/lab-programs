#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
int main()
{
    int i, j, k;
    int processes, resources;
    int max[MAX_PROCESSES][MAX_RESOURCES];
    int allocation[MAX_PROCESSES][MAX_RESOURCES];
    int available[MAX_RESOURCES];
    int need[MAX_PROCESSES][MAX_RESOURCES];
    int finish[MAX_PROCESSES];
    int safeSequence[MAX_PROCESSES];
    int work[MAX_RESOURCES];
    printf("Enter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the number of resources: ");
    scanf("%d", &resources);
    printf("Enter the maximum resource allocation matrix:\n");
    for (i = 0; i < processes; i++)
    {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++)
        {
            scanf("%d", &max[i][j]);
        }
    }
    printf("Enter the current resource allocation matrix:\n");
    for (i = 0; i < processes; i++)
    {
        printf("Process %d: ", i);
        for (j = 0; j < resources; j++)
        {
            scanf("%d", &allocation[i][j]);
            need[i][j] = max[i][j] - allocation[i][j];
        }
        finish[i] = 0;
    }
    printf("Enter the available resources: ");
    for (i = 0; i < resources; i++)
    {
        scanf("%d", &available[i]);
        work[i] = available[i];
    }
    int count = 0;
    int safe = 0;
    while (count < processes)
    {
        safe = 0;
        for (i = 0; i < processes; i++)
        {
            if (finish[i] == 0)
            {
                int flag = 1;
                for (j = 0; j < resources; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        flag = 0;
                        break;
                    }
                }
                if (flag)
                {
                    safeSequence[count++] = i;
                    finish[i] = 1;
                    for (k = 0; k < resources; k++)
                    {
                        work[k] += allocation[i][k];
                    }
                    safe = 1;
                }
            }
        }
        if (!safe)
        {
            break;
        }
    }
    if (count < processes)
    {
        printf("The system is in an unsafe state.\n");
    }
    else
    {
        printf("Safe sequence: ");
        for (i = 0; i < processes - 1; i++)
        {
            printf("P%d -> ", safeSequence[i]);
        }
        printf("P%d\n", safeSequence[processes - 1]);
    }
    return 0;
}