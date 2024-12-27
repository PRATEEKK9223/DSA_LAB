#include<stdio.h>
#include<stdlib.h>



char str[100],pat[100],rep[100],ans[100];

void read()
{
    printf("enter the main string\n");
    gets(str);
    printf("enter the patter string \n");
    gets(pat);
    printf("enter the replace string\n");
    gets(rep);
}

void match()
{
    int i,j,m,c,k;
    int flag=0;
    i=j=m=c=k=0;
    while(str[c]!='\0')
    {
        while(str[m]==pat[i]&&pat[i]!='\0')
        {
            m++;
            i++;
        }
        if(pat[i]=='\0')
        {
            flag=1;
            for(k=0;rep[k]!='\0';k++,j++)
            {
                ans[j]=rep[k];  
            }
            c=m;
            i=0;
        }
        else{
            ans[j]=str[c];
            c++;
            j++;
            m=c;
            i=0;
        }
    }
    ans[j]='\0';
    if(flag)
        printf("the resultant string is %s",ans);
    else
        printf("the pattern is not found\n");
}

void main()
{
    read();
    match();
}

