#include<stdio.h>
#include<stdlib.h>

int *stack,MAX,top=-1;

int isfull()
{
    if(top==MAX)
        return 1;
    else
        return 0;
}
int isempty()
{
    if(top==-1)
        return 1;
    else
        return 0;
}

void push(int ele)
{
    if(isfull())
        printf("stack is overdlow\n");
    else
        stack[++top]=ele;
}
int pop()
{
    if(isempty())
        return -1;
    else
        return stack[top--];
}

void display()
{
    if(isempty())
        printf("stack is empty\n");
    else{
        for(int i=top;i>=0;i--)
        {
            printf("%d\n",stack[i]);
        }
    }
}

void palindrom()
{
    char str[10];
    int flag=1;
    printf("enter the str to check palindrom\n");
    scanf("%s",str);
    for(int i=0;str[i]!='\0';i++)
        push(str[i]);
    for(int j=0;str[j]!='\0';j++)
    {
        char ele=pop();
        if(ele!=str[j])
        {
            flag=0;
            break;
        }
    }
    if(flag==1)
        printf("entered string %s is palindrom",str);
    else    
        printf("enterd string %s is not a palindrom\n",str);

}

void main()
{
    int choice,ele;
    printf("enter the size of the stack\n");
    scanf("%d",&MAX);
    stack=(int*)malloc(MAX*sizeof(int));
    while(1)
    {
        printf("enter your choice\n");
        printf("1-push:2-pop:3-palidrom:4-display :5-exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the element to push\n");
                scanf("%d",&ele);
                push(ele);
                break;
            case 2:
                ele=pop();
                if(ele==-1)
                    printf("stack is underflow\n");
                else
                    printf("the poped element is %d \n",ele);
                break;
            case 3:
                palindrom();
                break;
            case 4:
                display();
                break;
            case 5:
                exit(0);
                break;
            default :
                printf("invalid choice\n");
        }
    }
   

}



