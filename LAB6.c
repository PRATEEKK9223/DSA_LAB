#include<stdio.h>
#include<stdlib.h>

char *Queue;
int Max;
int front=-1,rare=-1;

int isfull()
{
    if(front==(rare+1)%Max)
        return 1;
    return 0;
}

int isempty()
{
    if(rare==-1 && front==-1)
        return 1;
    return 0;
}

void insert(char ele)
{
    if(isfull())
        printf("Queue is Overflow\n");
    else if(rare==-1 && front==-1)
    {
        front=rare=0;
        Queue[rare]=ele;
    }
    else{
        rare=(rare+1)%Max;
        Queue[rare]=ele;
    }
}
        
char delet()
{
    char ele;
    if(isempty())
        printf("Queue is underflow\n");
    else if(rare==front)
    {
        ele=Queue[front];
        rare=front=-1;
        return ele;
    }
    else{
        ele=Queue[front];
        front=(front+1)%Max;
        return ele;
    }
   
}

void display()
{
    if(isempty())
        printf("empty Queue\n");
    else{
        int i=front;
        while(i!=rare)
        {
            printf("%c-",Queue[i]);
            i=(i+1)%Max;
        }
        printf("%c",Queue[i]);
    }
}

void main()
{
    int choice;
    char ele;
    printf("enter the size of the Queue\n");
    scanf("%d",&Max);
    Queue=(char*)malloc(Max*sizeof(char));
    while(1)
    {
        printf("\nenter your choice\n");
        printf("1-insert\n2-delet\n3-display\n4-exit...\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter the character\n");
                getchar();
                scanf("%c",&ele);
                insert(ele);
                break;
            case 2:
                printf("deleted characet is %c\n",delet());
                break;
            case 3:
                printf("Queus character are\n");
                display();
                break;
            case 4:
                exit(0);
            default:
                printf("invalid choice\n");
        }

    }
}
        

