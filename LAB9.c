#include<stdio.h>
#include<stdlib.h>
#include<math.h>

struct node{
    int coeff,Xexp,Yexp,Zexp,flag;
    struct node *link;
};

struct node* creat()
{
    struct node *newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    if(newnode==NULL)
    {
        printf("memory not allocated\n");
        exit(0);
    }
    return newnode;       
}

struct node* attach(int coeff,int Xexp,int Yexp,int Zexp,struct node* head)
{
    struct node *newnode,*temp;
    newnode=creat();
    newnode->coeff=coeff;
    newnode->Xexp=Xexp;
    newnode->Yexp=Yexp;
    newnode->Zexp=Zexp;
    newnode->flag=0;
    temp=head->link;
    while(temp->link!=head)
    {
        temp=temp->link;
    }
    temp->link=newnode;
    newnode->link=head;

    return head;

}

struct node* read_poly(struct node *head)
{
    int n;
    int coeff,Px,Py,Pz;
    printf("\nenter the number of terms\n");
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
        printf("\nenter the %d term\n",i+1);
        printf("\nenter the coeff,exponents of X Y Z\n");
        scanf("%d %d %d %d",&coeff,&Px,&Py,&Pz);
        head=attach(coeff,Px,Py,Pz,head);
    }
    return head;
}

void display(struct node *head)
{
    if(head->link==head)
        printf("empty polynomial\n");
    else{
        struct node *temp;
        temp=head->link;
        while(temp!=head)
        {
            printf("%dX^%dY^%dZ^%d ",temp->coeff,temp->Xexp,temp->Yexp,temp->Zexp);
            if(temp!=head)
                printf("+");
            temp=temp->link;
        }
    }
}

void evaluate(struct node *head)
{
    int X,Y,Z;
    int sum=0;
    printf("\nenter the valeus of X Y Z\n");
    scanf("%d %d %d",&X,&Y,&Z);
    struct node *temp;
    temp=head->link;
    while(temp!=head)
    {
        sum+=(temp->coeff)*(pow(X,temp->Xexp)*(pow(Y,temp->Yexp)*(pow(Z,temp->Zexp))));
        temp=temp->link;
    }
    printf("\nthe evaluated result =%d\n",sum);
}

struct node* add_poly(struct node *h1,struct node *h2,struct node *h3)
{
    struct node *p1,*p2;
    int x1,y1,z1,coeff1;
    int x2,y2,z2,coeff2;
    int coeffers;
    
    p1=h1->link;
    while(p1!=h1)
    {
        int considered=0;
        x1=p1->Xexp;
        y1=p1->Yexp;
        z1=p1->Zexp;
        coeff1=p1->coeff;

        p2=h2->link;
        while(p2!=h2)
        {
            x2=p2->Xexp;
            y2=p2->Yexp;
            z2=p2->Zexp;
            coeff2=p2->coeff;

            if(x1==x2 && y1==y2 && z1==z2)
            {
                coeffers=coeff1+coeff2;
                considered=1;
                p2->flag=1;
                if(coeffers!=0)
                    h3=attach(coeffers,x1,y1,z1,h3);
            }
            p2=p2->link;
        }
        if(considered==0)
            h3=attach(coeff1,x1,y1,z1,h3);
        p1=p1->link;   
    }
    p2=h2->link;
    while(p2!=h2)
    {
        if(p2->flag==0)
            h3=attach(p2->coeff,p2->Xexp,p2->Yexp,p2->Zexp,h3);
        p2=p2->link;
    }
    return h3;

}

void main()
{
    struct node *head,*h1,*h2,*h3;

    head=creat();
    h1=creat();
    h2=creat();
    h3=creat();

    head->link=head;
    h1->link=h1;
    h2->link=h2;
    h3->link=h3;

    while(1)
    {
        int choice;
        printf("enter your choice\n");
        printf("1-evaluation::2-Addition::3-exit....\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("evaluation of polynomial\n");
                head=read_poly(head);
                display(head);
                evaluate(head);
                break;
            case 2:
                printf("addition of two polynomials\n");
                printf("enter poluy 1\n");
                h1=read_poly(h1);
                display(h1);

                printf("enter poluy 2\n");
                h2=read_poly(h2);
                display(h2);

                h3=add_poly(h1,h2,h3);
                printf("final addition\n");
                display(h3);



        }
    }
}
