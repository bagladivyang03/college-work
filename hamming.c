#include<stdio.h>
int main()
{
	int a[12];
	int i,j=0,k=0,l=0,m=0,s=0,s1=0,s2=0,s3=0;
	for(i=0;i<12;i++)
	{
		if(i!=0 && i!=1 && i!=3 && i!=7)
		{
			scanf("%d",&a[i]);
						
			
		}
		else	
		{
			a[i]=0;
		}
	}
	for(j=0;j<12;j=j+2)
	{
		if(a[j]==1)
		{
			s++;
		}
		
	}
	if(s%2==1)
	{
		a[0]=1;
	}	
	else
	{
		a[0]=0;
	}
	while(k<11)
	{
		if(k==2 || k==5 || k==6 || k==9 || k==10)
		{
			if(a[k]==1)
			{
				s1++;
			}
		}k++;
	}
	if(s1%2==1)
	{
		a[1]=1;
	}
	else
	{
		a[1]=0;
	}
	while(l<11)
	{
		if(l==4 || l==5 || l==6 || l==11)
		{
			if(a[l]==1)
			{
				s2++;
			}	
		}
		l++;
	}
	if(s2%2==1)
	{
		a[3]=1;
	}
	else
	{
		a[3]=0;
	}
	while(m<11)
	{
		if(m==8 || m==9 || m==10 || m==11)
		{
			if(a[m]==1)
			{
				s3++;
			}	
		}m++;
	}
	if(s3%2==1)
	{
		a[7]=1;
	}
	else
	{
		a[7]=0;
	}
	for(i=0;i<12;i++)
	{
		printf("%d",a[i]);
	}
return 0;
}
