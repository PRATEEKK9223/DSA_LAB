#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
char stack[10];
int top=-1;

void push(char ele)
{
    stack[++top]=ele;
}

char pop()
{
    return stack[top--];
}

int stack_priority(char sys)
{
    if(sys=='#')
        return -1;
    if(sys=='(')
        return 0;
    if(sys=='+'|| sys=='-')
        return 2;
    if(sys=='*'|| sys=='/'||sys=='%')
        return 4;
    if(sys=='^')
        return 5;
}

int input_priority(char sys)
{
    
    if(sys=='(')
        return 9;
    if(sys=='+'|| sys=='-')
        return 1;
    if(sys=='*'|| sys=='/'||sys=='%')
        return 3;
    if(sys=='^')
        return 6;
}

void main()
{
    char infix[100],ele;
    printf("enter the valid infix expreesion\n");
    scanf("%s",infix);
    printf("postfix expreesion is\n");
    push('#');
    for(int i=0;infix[i]!='\0';i++)
    {
        if(isalnum(infix[i]))
            printf("%c",infix[i]);
        else if(infix[i]=='(')
            push(infix[i]);
        else if(infix[i]==')')
        {
            while(ele=pop()!='(')
                printf("%c",infix[i]);
        }
        else{
            while(input_priority(infix[i]) <= stack_priority(stack[top]))
                printf("%c",pop());
            push(infix[i]);        
        }    
    }
    while(top!=0)
        printf("%c",pop());
}