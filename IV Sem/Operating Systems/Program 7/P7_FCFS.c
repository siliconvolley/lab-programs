#include<stdio.h>
#include<stdlib.h>

int main()
{
	int ReadyQueue[100], i, n, TotalHeadMov=0, initial;
	printf("Enter the number of requests: ");
	scanf("%d", &n);
	printf("Enter the sequence of request: ");
	for(i=0; i<n; i++)
		scanf("%d", &ReadyQueue[i]);
	printf("Enter initial head position: ");
	scanf("%d", &initial);
	for(i=0; i<n; i++)
	{
		TotalHeadMov = TotalHeadMov + abs(ReadyQueue[i]-initial);
		initial = ReadyQueue[i];
	}
	printf("Total Head Movement = %d\n",TotalHeadMov);
}
