#include<stdio.h>
#include<stdlib.h>
struct term{
    int f_no;
    char bit;
    int count;
};
typedef struct term pterm;
void dis_buff(int buffer[10],int no_of_frames)
{
    int k;
    for(k=0;k<no_of_frames;k++)
    {
        if(buffer[k]!=-1)
        {
            printf("%4d",buffer[k]);
        }
        else{
            printf("  -");
        }
    }
}
void init(int buffer[10],pterm pg_table[10],int no_of_frames)
{
    int i;
    for(i=0;i<no_of_frames;i++)
    {
        buffer[i]=-1;
    }
    for(i=0;i<10;i++)
    {
        pg_table[i].bit = 'I';
    }
}

void fifo(int refstr[20],int n,int no_of_frames)
{
    pterm pg_table[10];
    int i,j,p,pg_no,front,buffer[10];
    int page_faults=0;
    j=0;front=0;
    init(buffer,pg_table,no_of_frames);
    printf("\nPAGE REPLACEMENT USING FIFO\n");
    printf("\n");
    for(i=0;i<n;i++)
    {
        pg_no = refstr[i];
        printf("\nFor page no. %4d :",pg_no);
        if(pg_table[pg_no].bit=='I')
        {
            if(j<no_of_frames)
            {
                buffer[j]=pg_no;
                j++;
            }
            else{
                p = buffer[front];
                pg_table[p].bit = 'I';
                buffer[front] = pg_no;
                front = (front+1)%no_of_frames;
            }
            pg_table[pg_no].bit = 'V';
            page_faults++;
            dis_buff(buffer,no_of_frames);
            printf("  F");
        }
    }
    printf("\nThe total no. of page faults : %d",page_faults);
}
void lru(int refstr[20],int n,int no_of_frames)
{
    pterm pg_table[10];
    int i,j,k,p,pg_no,front,buffer[10];
    int page_faults=0;
    int r,m,found,min;
    j=0;
    init(buffer,pg_table,no_of_frames);
    printf("\nPAGE REPLACEMENT USING LRU\n");
    printf("\n");
    for(i=0;i<n;i++)
    {
        pg_no=refstr[i];
        pg_table[pg_no].count=i;
        printf("\nFor page no: %4d",pg_no);
        if(pg_table[pg_no].bit=='I')
        {
            if(j<no_of_frames)
            {
                buffer[j] = pg_no;
                j++;
            }
            else{
                min =99;
                for(k=0;k<no_of_frames;k++)
                {
                    p = buffer[k];
                    if(pg_table[p].count < min)
                    {
                        min = pg_table[p].count;
                        r=k;
                    }
                }
            }
                p = buffer[r];
                buffer[r] = pg_no;
                pg_table[p].bit = 'V';
                page_faults++;
                dis_buff(buffer,no_of_frames);
                printf("  F");
        }
    }
    printf("\n The no. of page fauls : %d",page_faults);
}
int main()
{
    int refstr[20],i,n,no_of_frames;
    printf("Enter the length of refernce string");
    scanf("%d",&n);
    printf("Enter no of frames ");
    scanf("%d",&no_of_frames);
    printf("Enter the refernce string \n");
    for(int i=0;i<n;i++)
    {
        printf("refstr[%d]",i);
        scanf("%d",&refstr[i]);
    }
    fifo(refstr,n,no_of_frames);
    lru(refstr,n,no_of_frames);
return 0;
}
