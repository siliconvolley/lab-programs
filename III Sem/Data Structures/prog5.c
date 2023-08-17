#include<stdio.h>
#include<stdlib.h>
//Student Data using DLL

int count;
struct node
{
	float marks1,marks2,marks3;
	char usn[10],name[20],dept[20],phno[15];
	struct node *nextlink;
	struct node *prevlink;
};
typedef struct node *NODE;
NODE first=NULL;
NODE getnode()
{
	NODE x;
	x = (NODE)malloc(sizeof(struct node));
	return x;
}
NODE create_node()
{
	NODE newnode;
	newnode= getnode();
	printf("Enter Students Details : \n");
	printf("Enter usn : ");
	scanf("%s", newnode->usn);
	printf("Enter Name : ");
	scanf("%s", newnode->name);
	printf("Enter Dept : ");
	scanf("%s", newnode->dept);
	printf("Enter marks1 : ");
	scanf("%f", &(newnode->marks1));
	printf("Enter marks2 : ");
	scanf("%f", &(newnode->marks2));
	printf("Enter marks3 : ");
	scanf("%f", &(newnode->marks3));
	printf("\n Enter Phone No : ");
	scanf("%s", newnode->phno);
	newnode->prevlink = NULL;
	newnode->nextlink = NULL;
	count++;
	return newnode;
}
void disp_deleted(NODE newnode)
{
	printf("The following Student detail is deleted:\n");
	printf("USN | Name | Dept | Marks1 | Marks2 | Marks3 | Ph. No \n");
	printf("----------------------------------------------------------------------------------\n");
	printf("%s | %s | %s | %.2f | %.2f | %.2f | %s \n",newnode->usn,newnode->name,newnode->dept, newnode->marks1,newnode->marks2,newnode->marks3,newnode->phno);
	count--;
}
void insert_front()
{
	NODE newnode;
	newnode = create_node();
	if(first == NULL)
	{
		first = newnode;
	}
	else
	{
		newnode->nextlink = first;
		first->prevlink = newnode;
		first = newnode;
	}
}
void delete_front()
{
	NODE newnode;

	if(first == NULL)
	{
		printf("List is Empty\n");

	}
	else if(first->nextlink == NULL)
	{
		disp_deleted(first);
		free(first);
		first = NULL;
	}
	else
	{
		newnode = first;
		disp_deleted(newnode);
		first = first->nextlink;
		first->prevlink = NULL;
		newnode->nextlink = NULL;
		free(newnode);
		newnode = NULL;
	}
}
void insert_rear()
{
	NODE newnode,cur;
	newnode= create_node();
	if(first == NULL)
	{
		first = newnode;
	}
	else
	{
		cur = first;
		while(cur->nextlink !=NULL)
		{
			cur = cur->nextlink;
		}

		cur->nextlink = newnode;
		newnode->prevlink = cur;
	}
}
void delete_rear()
{
	NODE cur;
	if(first == NULL)
	{
		printf("List is empty\n");
	}
	else if(first->nextlink == NULL)
	{
		disp_deleted(first);
		free(first);
		first = NULL;
	}
	else
	{
		cur = first;
		while(cur->nextlink != NULL)
		{
			cur = cur->nextlink;
		}
		disp_deleted(cur);
		cur->prevlink->nextlink = NULL;
		cur->prevlink = NULL;
		free(cur);
		cur = NULL;
	}
}
void display()
{
	NODE cur;
	float total, average;
	if(first == NULL)
	{
		printf("List is empty\n");
	}
	else
	{
		cur = first;
		printf("The student details in doubly Linked list from beginning : \n");
		printf("USN | Name | Dept | Marks1 |Marks2 | Marks3 | Total Marks | Average | Ph. No \n");
		printf("----------------------------------------------------------------------------------\n");
		while(cur != NULL)
		{
			total=cur->marks1 + cur->marks2 + cur->marks3;
			average=total/3;
			printf("%s | %s | %s | %.2f | %.2f | %.2f | %.2f | %.2f | %s \n",cur->usn,cur->name, cur->dept,cur->marks1,cur->marks2,cur->marks3,total, average, cur->phno);
			cur = cur->nextlink;
		}
		printf("----------------------------------------------------------------------------------\n");
		printf("Number of Nodes = %d\n",count);
	}
}
void main()
{
	int choice,i,n;
	while(1)
	{
		choice=0;
		printf("----------------------------------------MENU--------------------------------------\n");
		printf("1. Create a DLL of N student by using End Insertion\n");
		printf("2. Display Status and Count of nodes\n");
		printf("3. Insertion at rear\n");
		printf("4. Deletion at rear\n");
		printf("5. Insertion at front\n");
		printf("6. Delete at front\n");
		printf("7. Exit\n");
		printf("----------------------------------------------------------------------------------\n");
		printf("Enter choice : ");
		scanf("%d", &choice);
		switch (choice)
		{
			case 1:	printf("Enter number of student:");
				scanf("%d",&n);
				for(i=0;i<n;i++)
					insert_rear();
				break;
			case 2:	display(); break;
			case 3:	insert_rear(); break;
			case 4:	delete_rear(); break;
			case 5:	insert_front();
			break;
			case 6: delete_rear();
			break;
			case 7: return;
			default:printf("Invalid");
			break;
		}
	}
}