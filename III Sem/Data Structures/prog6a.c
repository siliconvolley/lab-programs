#include<stdio.h>
#include<stdlib.h>
//Evaluate a Given Polynomial

int c=1,count=1;

struct node{
	int coef;
	int px;
	int py;
	int pz;
	struct node *link;
};
struct node *new,*head,*temp,*tail;

void newNode()
{
	new=(struct node*)malloc(sizeof(struct node));
	printf("Enter the Coefficients & Powers of x, y & z: ");
	scanf("%d%d%d%d", &new->coef, &new->px, &new->py, &new->pz);

	new->link=head;
	tail->link=new;
	tail=new;
}

int display(int count)
{
	temp=head;
	while(temp->link!=head)
	{
		printf("%d(X^%d)(Y^%d)(Z^%d)+",temp->coef,temp->px,temp->py,temp->pz);
		count++;
		temp=temp->link;	
	}
	printf("%d(X^%d)(Y^%d)(Z^%d)\n",temp->coef,temp->px,temp->py,temp->pz);

	return count;
}

int power(int ba,int po)
{
	int i,x=1;
	for(i=0;i<po;i++)
		x=x*ba;
	return x;
}

void evaluate(int count)
{
	int p[count],a=0;
	int i,x,y,z,sum=0;
	printf("Enter the values for x, y and z: "); 
	scanf("%d%d%d",&x,&y,&z);
	temp=head;
	while(temp->link!=head)
	{
		p[a] = (temp->coef) * power(x,temp->px) * power(y,temp->py) * power(z,temp->pz);
		a++;
		temp=temp->link;	
	}
	p[a] = (temp->coef) * power(x,temp->px) * power(y,temp->py) * power(z,temp->pz);
	for(i=0;i<count;i++)
		sum=sum+p[i];

	printf("The Result is %d\n",sum);
	return;
}

void main()
{
	int terms, count = 1;
	head = NULL;
	tail = NULL;
	temp = NULL;

	printf("*****Evaluate a Polynomial Expression*****\n");	

	new=(struct node*)malloc(sizeof(struct node));

	printf("Enter the no. of terms: ");
	scanf("%d", &terms);
	if(terms > 0){
		printf("Enter the Coefficients & Powers of x, y & z: ");
		scanf("%d%d%d%d", &new->coef, &new->px, &new->py, &new->pz);
		head=new;
		tail=new;
		new->link=head;

		for(int i=0; i<terms-1; i++)
			newNode();
		
		//Printing the created equation
		printf("\nGiven Polynomial Expression is \n");
		count = display(count);

		//Evaluating the expression
		evaluate(count);
	}
}
