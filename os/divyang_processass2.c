#include<unistd.h>
#include<sys/wait.h>
#include<stdio.h>
void ascending(int a[20],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]>a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void descending(int a[20],int n)
{
    for(int i=0;i<n-1;i++)
    {
        for(int j=0;j<n-i-1;j++)
        {
            if(a[j]<a[j+1])
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}
void display(int a[20],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
    printf("\n");
}
int main()
{
    pid_t pid;
int st;
   int n;
   printf("Enter the array size :");
   scanf("%d",&n);
   int a[n];
   for(int i=0;i<n;i++)
   {
       printf("Enter the element %d :",i+1);
       scanf("%d",&a[i]);
   }
   pid = fork();
   if(pid==0)
   {
       printf("This is the child process and ID is %d\n",getpid());
       descending(a,n);
       display(a,n);
      
   }
   else
   {
	wait(&st);
    if(WIFEXITED(st))
    {
      printf("Child's terminated status=%d\n",WEXITSTATUS(st));
    }
       printf("This is the parent process and ID is %d\n",getpid());
       ascending(a,n);
       display(a,n);
   }
   
}
/*OUTPUT:
Enter the array size :5                                                                                            
Enter the element 1 :3                                                                                             
Enter the element 2 :4                                                                                             
Enter the element 3 :1                                                                                             
Enter the element 4 :2                                                                                             
Enter the element 5 :5                                                                                             
This is the child process and ID is 897                                                                            
5       4       3       2       1                                                                                  
Child's terminated status=0                                                                                        
This is the parent process and ID is 896                                                                           
1       2       3       4       5 
*/