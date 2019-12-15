#include<stdio.h>
#include<string.h>
void gensq(int n);

int main()
{
	int n;	
	int magicsquare[n][n];
	printf("enter the value of n:");
	scanf("%d",&n);
	
	gensq(n);

	
}
void gensq(int n)
{
	int magicsquare[n][n];
	memset(magicsquare,0,sizeof(magicsquare));
	int i=n/2;
	int j=n-1;
	//printf("%d%d\n",i,j);
	for(int nu=1;nu<=n*n;)
	{
		if(i==-1 && j==n)
		{
			i=0;
			j=n-2;
		}
		else  
		{
			if(i<0)
			i=n-1;
			if(j==n)
			j=0;
			
		}
		if(magicsquare[i][j]!=0)
		{
			i=i+1;
			j=j-2;
			magicsquare[i][j]=nu;	
			
			
		}
		else
		{
			magicsquare[i][j]=nu;	
			
			
			
		}
		i=i-1;
		j=j+1;nu++;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			printf("%d\t",magicsquare[i][j]);
		}
		printf("\n");
	}
}
