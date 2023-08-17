#include<stdio.h>
#include<ctype.h>
//Infix To Postfix

#define N 20
char stack[N];
int top=-1;
void push(char y);
char pop();
int prior(char t);


void push(char y){
    stack[++top]=y;

}

char pop(){
    if(top==-1){
        return 1;
    }
    else{
        return stack[top--];
    }
}

int prior(char t){
    if(t=='('){
        return 0;
    }
    if(t=='+'||t=='-'){
        return 1;
    }
    if(t=='*'||t=='/'){
        return 2;
    }
}

void main(){
    char exp[N];
    char x;
    printf("ENTER EXPRESSION\n");
    scanf("%s",exp);
    char *e;
    e=exp;
    while(*e!='\0'){
        
        if(isalnum(*e)){
            printf("%c",*e);

        }
        else if(*e=='('){
            push(*e);
        }
        else if(*e==')'){
            while((x=pop())!='('){
                printf("%c",x);
            }

        }
        else{
            if(prior(stack[top])>prior(*e)){
                printf("%c",pop());
            }
            if(prior(stack[top])==prior(*e)){
                printf("%c",pop());
            }

            push(*e);
        }
        e++;
    }
    while(top!=-1){
        printf("%c",pop());
    }
    printf("\n");

}