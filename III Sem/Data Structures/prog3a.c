#include<stdio.h>
#include<ctype.h>
#include<string.h>
//Postfix Evaluation

#define MAX 100
int top = -1, y;
char postfix[MAX];
int stack[MAX];

void push(int item){
	if(top == MAX-1){
		printf("Stack Overflow");
		return;
	}
	else{
		top++;
		stack[top] = item;
	}
}

int pop(){
	if(top == -1){
		printf("Stack Underflow");
		return 0;
	}
	else{
		int item;
		item = stack[top];
		top--;
		return item;
	}
}

void evaluate(){
	int i, val, A, B, x=1;
	char ch;
	
	for(i=0; postfix[i]!=')';i++){
		ch = postfix[i];
		if(isdigit(ch)){
			push(ch - '0');
		}
		else if(ch=='+' || ch=='-' || ch=='*' || ch=='/' || ch=='^'){
			A = pop();
			B = pop();
			switch(ch){
				case'+': val = B+A;
					 break;
				case'-': val = B-A;
					 break;
				case'*': val = B*A;
					 break;
				case'/': val = B/A;
					 break;
				case'^': val = 1;
					 for(x=0; x<=B-1; x++)
					 	val *= A;
					 break;

			}
			push(val);
		}
	}
	printf("\nResult of given Postfix expression is %d\n", pop());
}

void main(){
	int i;
	printf("Enter postfix expression to evaluate:\nPress ')' at the end of expression: \n");
	for(i=0; i<MAX-1; i++){
		scanf("%c", &postfix[i]);
		if(postfix[i] == ')')
			break;
	}
	y = strlen(postfix);
	evaluate(postfix);
}