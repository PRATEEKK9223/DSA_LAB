#include<stdio.h>
#include<stdlib.h>
int count=0;
void main()
{
    int n;
    printf("enter the number of disck\n");
    scanf("%d",&n);
    tower(n,'A','B','C');
    printf("the number of moves is %d",count);
}

void tower(int n,int src,int dest,int aux)
{
    if(n==1)
    {
        printf("the disck 1 is move from %c to %c",src,dest);
        return ;
    }
    else{
        printf("the disck %d move from %c to %c",)
        tower(n-1,src,aux,dest);

    }
}