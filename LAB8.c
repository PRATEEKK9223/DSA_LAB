#include<stdio.h>
#include<stdlib.h>

struct node {
    char SSN[10],name[10],dept[10],phnum[10];
    struct node *next,*prev;
};

struct node *head=NULL,*newnode,*tail;

 struct node* getNode()
 {
    newnode=(struct node*)malloc(sizeof(struct node));
    printf("enter the details\n");
    scanf("%s %s %s %s",newnode->SSN,newnode->name,newnode->dept,newnode->phnum);
    newnode->next=0;
    newnode->prev=0;
    return newnode;
 }

 void insert_At_Front()
 {
    newnode=getNode();
    if(head==NULL)
        tail=head=newnode;
    else{
        newnode->next=head;
        head->prev=newnode;
        head=newnode;
    } 
 }
 void insert_At_end()
 {
    newnode=getNode();
    if(head==NULL)
        tail=head=newnode;
    else{
        tail->next=newnode;
        newnode->prev=tail;
        tail=newnode;
    }
 }

void delet_At_front()
{
    struct node *temp=head;
    if(head==0)
        printf("empty DLL\n");
    else{
        head=head->next;
        head->prev=0;
        free(temp);
    }
}
void delet_At_end()
{
    struct node *temp;
    if(head==NULL)
        printf("empty DLL\n");
    else{
        temp=tail;
        tail=temp->prev;
        tail->next=0;
        free(temp);
    }
}

void creat(int N)
{
    for(int i=0;i<N;i++)
    {
        insert_At_end();
    }
}

void display()
{
    int count=0;
    struct node *temp=head;
    if(head==0)
        printf("empoty DLL\n");
    else{
        printf("SNN\t NAME\t department\t phone number\n");
        printf("__________________________\n");
        while(temp!=0)
        {
            printf("%s\t %s\t %s\t %s\n",temp->SSN,temp->name,temp->dept,temp->phnum);
            temp=temp->next;
            count++;
        }
        printf("the number of nodes is %d\n",count);
    }
}
void main()
{
    int choice,N;
    while(1)
    {
        printf("1-creat N employee list\n 2-insert At beging\n 3-insert At end \n 4-delet At beging\n 5-delet At end\n 6-display\n 7-exit...\n");
        printf("enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("enter number of employees\n");
                scanf("%d",&N);
                creat(N);
                break;
            case 2:
                insert_At_Front();
                break;
            case 3:
                insert_At_end();
                break;
            case 4:
                delet_At_front();
                break;
            case 5:
                delet_At_end();
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


