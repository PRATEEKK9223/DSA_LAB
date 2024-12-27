#include<stdio.h>
#include<stdlib.h>

struct WEEK{
    char *day;
    int dd, mm, yy;
    char *event;
};

struct WEEK *ptr;
int n,n1,n2;

void creat()
{
    printf("enter the number of days you want\n");
    scanf("%d",&n);
    ptr=(struct WEEK*)malloc(n*sizeof(struct WEEK));
}

void read()
{
    printf("enter the data for a week\n");
    for(int i=0;i<n;i++)
    {
        printf("eneter the size of the day\n");
        scanf("%d",&n1);
        printf("eneter the size of the event\n");
        scanf("%d",&n2);
        ptr[i].day=(char*)malloc(n1*sizeof(char));
        ptr[i].event=(char*)malloc(n2*sizeof(char));
        printf("enter the day date(dd-mm-yy) event\n");
        scanf("%s %d %d %d ",ptr[i].day,&ptr[i].dd,&ptr[i].mm,&ptr[i].yy);
        //getchar();
        //fflush(stdin);
        gets(ptr[i].event);
    }

}

void display()
{
    printf("DAY\t\tDATE \t\tEVENT\n");
    printf("____________________________________\n");
    for(int i=0;i<n;i++)
    {
        printf("%s\t %d-%d-%d\t",ptr[i].day,ptr[i].dd,ptr[i].mm,ptr[i].yy);
        puts(ptr[i].event);
    }
   
}
int main()
{
    creat();
    read();
    display();
}
