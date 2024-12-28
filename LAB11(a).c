#include<stdio.h>
#include<stdlib.h>

int a[10][10],n;

void BFS(int src)
{
    int Queue[1],f=-1,r=-1;
    int vis[10];
    for(int j=1;j<=n;j++)
        vis[j]=0;
    vis[src]=1;
    Queue[++r]=src;

    while(f<r)
    {
        int i=Queue[++f];
        for(int j=1;j<=n;j++)
        {
            if(a[i][j]==1 && vis[j]!=1)
            {
                vis[j]=1;
                Queue[++r]=j;
            }
        }

    }
    for(int j=1;j<=n;j++)
    {
        if(vis[j]!=1)
            printf("node %d is not rechable\n",j);
        else
            printf("node %d is rechable\n",j);
    }


} 

int main()
{
    int src;
    printf("enetrt te number of nodes\n");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("entert the sorce node\n");
    scanf("%d",&src);
    BFS(src);

}