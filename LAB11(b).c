#include<stdio.h>
#include<stdlib.h>

int a[10][10],n;

void DFS(int src)
{
    int stack[10];
    int top=-1;
    int vis[10];
    for(int j=1;j<=n;j++)
    {
        vis[j]=0;
    }
    vis[src]=1;
    stack[++top]=src;
    while(top!=-1)
    {
        int i=stack[top--];
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1 && vis[j]!=1)
            {
                vis[j]=1;
                stack[++top]=j;
            }
        }
    }
    for(int j=1;j<=n;j++)
    {
        if(vis[j]!=1)
            printf("node %d not reachable\n",j);
        else    
            printf("node %d is reachable\n",j);
    }
}

void main()
{
    int src;
    printf("enter the number nodes\n");
    scanf("%d",&n);
    printf("enter the adjacency matrix\n");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }

    printf("enter the source node \n");
    scanf("%d",&src);
    DFS(src);
}
