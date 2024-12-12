#include<stdio.h>
#include<stdlib.h>

struct node{
    char USN[10],name[10],program[10];
    int sem;
    struct node *next;
};

struct node *head=NULL,*newnode;

struct node* getnode()
{
   newnode=(struct node*)malloc(sizeof(struct node));
   printf("enter the details\n");
   scanf("%s %s %s %d",&newnode->USN,newnode->name,newnode->program,&newnode->sem);
   newnode->next=0;
    return newnode;
}

void insertAtFront()
{
    newnode=getnode();
    if(head==NULL)
        head=newnode;
    else{
        newnode->next=head;
        head=newnode;
    }
}

void creat(int N)
{
    for(int i=0;i<N;i++)
        insertAtFront();
}

void insertAtend()
{
    struct node *temp=head;
    newnode=getnode();
    if(head==NULL)
        head=newnode;
    else{
        while(temp->next!=0)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}

void deletAtFront()
{
    struct node *temp=head;
    if(head==NULL)
        printf("empty LL\n");
    else{
        head=head->next;
        temp->next=0;
        free(temp);  
    }
}

void deletAtend()
{
    struct node *temp=head,*next;
    if(head==NULL)
        printf("empty\n");
    else{
        while(temp->next->next!=0)
        {
            temp=temp->next;
            
        }
        next=temp->next;
        temp->next=0;
        free(next);
    }
}

void display()
{
    int count=0;
    struct node *temp=head;
    if(head==0)
        printf("empty LL\n");
    else{
        printf("USN\t NAME\t PROGARMM\t SEM\n");
        printf("____________________________________\n");
        while(temp!=0)
        {
            printf("%s\t %s\t %s\t %d\n",temp->USN,temp->name,temp->program,temp->sem);
            temp=temp->next;
            count++;
        }
        printf("the number of nodes =%d\n",count);

    }
}

void main()
{
    int choice,N;
    while(1)
    {
        printf("1-creat N students list\n 2-insert At beging\n 3-insert At end \n 4-delet At beging\n 5-delet At end\n 6-display\n 7-exit...\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter number of students\n");
                scanf("%d",&N);
                creat(N);
                break;
            case 2:
                insertAtFront();
                break;
            case 3:
                insertAtend();
                break;
            case 4:
                deletAtFront();
                break;
            case 5:
                deletAtend();
                break;
            case 6:
                display();
                break ;
            case 7:
                exit(0);
            default :
                printf("invalid choice\n");
        }
    }
}

