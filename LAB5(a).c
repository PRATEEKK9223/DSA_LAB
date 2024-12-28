#include<stdio.h>
#include<ctype.h>

int evaluate(int op1,int op2,char sym)
{
    switch(sym)
    {
        case '+':
            return op1+op2;
        case '-':
            return op1-op2;
        case '*':
            return op1*op2;
        case '/':
            return op1/op2;
        case '%':
            return op1%op2;
    }
}


void main()
{
    char suffix[10];
    int stack[10],top=-1;
    int op1,op2;
    printf("enter the valid suffix expreesion\n");
    scanf("%s",suffix);
  
    for(int i=0;suffix[i]!='\0';i++)
    {
        char sym=suffix[i];
        if(isdigit(sym))
        {
            int ele=sym -'0';
            stack[++top]=ele;
        }
        else{
            op1=stack[top--];
            if(top==-1)
               break;
            op2=stack[top--];

            int result=evaluate(op2,op1,sym);
            stack[++top]=result;
           
        }
    }
    if(top==0)
        printf("result=%d",stack[top]);
    else    
        printf("invalid suffix exprsion\n");

}