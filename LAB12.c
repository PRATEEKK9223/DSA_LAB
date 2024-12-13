#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define BS 10

struct employee{
    int emp_num;
    char name[10];
};

struct employee HT[BS];
struct employee input;

FILE *outfile,*infile;

void display()
{
    printf("\n...........HASH TABLE...............\n");
    printf("BOCKET_NUM\t EMP_NUM \tNAME\n");
    for(int i=0;i<BS;i++)
    {
        printf("%d\t\t%d\t\t%s\n",i,HT[i].emp_num,HT[i].name);
    }
}

void main()
{
    int c=0,key,j;
    outfile=fopen("employee.dat","w+");
    for(int i=0;i<BS;i++)
    {
        HT[i].emp_num=-1;
        strcpy(HT[i].name,"");
    }

    printf("enter 0 for employenum toend input\n");
    while(1)
    {
        printf("enter emp id\n");
        scanf("%d",&input.emp_num);

        if(input.emp_num==0)
            break;
        
        printf("first name\n");
        scanf("%s",&input.name);

        fwrite(&input,sizeof(struct employee),1,outfile);
    }
    fclose(outfile);

    infile=fopen("employee.dat","r");
    while(fread(&input,sizeof(struct employee),1,infile))
    {
        printf("EMP_NUM=%d  NAME=%s",input.emp_num,input.name);
        c++;
        if(c>BS)
        {
            printf("\n.......hash table overflow...........\n");
           // break;
        }
        key=(input.emp_num)%BS;
        if(HT[key].emp_num==-1)
        {
            HT[key].emp_num=input.emp_num;
            strcpy(HT[key].name,input.name);
            display();
        }
        else{
            printf(".........collision at bocket %d fr emp number %d\n",key,input.emp_num);
            j=(key+1)%BS;
            while(j!=key)
            {
                if(HT[j].emp_num==-1)
                {
                    printf("\n.............using linear brobing solve collision.........\n");
                    HT[j].emp_num=input.emp_num;
                    strcpy(HT[j].name,input.name);
                    display();
                    break;
                }
                else    
                    j=(j+1)%BS;
            }
        }


        

    }

}
