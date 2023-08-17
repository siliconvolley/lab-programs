#include<stdio.h>
#include<stdlib.h>
//Hashing

int key,n,m,*ht,hi,elec,flag;

void createht()
{
    int i;
    ht = (int*)malloc(m*sizeof(int));
    if(m==0)
    {
        printf("Unable to create the hash table\n");
        exit(0);
    }
    else
    for(i=0; i<m; i++)
        ht[i] = -1;
}

void insertht(int key)
{
    hi = key % m;
    while(ht[hi] != -1)
    {
        hi = (hi+1)%m;
        flag = 1;
    }
    if(flag)
    {
        printf("Collision Detected and avoided by Linear Probing!\n");
        flag = 0;
    }
    ht[hi] = key;
    elec++;
}

void displayht()
{
    int i;
    if(elec == 0)
    {
        printf("Hash Table is empty\n");
        return;
    }
    printf("Hash Table contents are:\n");
    for(i=0; i<m; i++)
        printf("[%d] --> %d\n", i, ht[i]);
}

void main()
{
    int i;
    printf("Enter the No. of Employee Records: ");
    scanf("%d", &n);
    printf("Enter the two digit memory locations: ");
    scanf("%d", &m);
    createht();
    printf("Enter four digit key values of Employee records\n");
    for(i=0; i<n; i++)
    {
        scanf("%d", &key);
        if(elec == m)
        {
            printf("Hash table is full.\n");
            break;
        }
        insertht(key);
    }
    displayht();
}