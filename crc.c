#include<stdio.h>
int main()
{
	int gen[30],data[30],r[10],dn,gn,i,j,cnt,tra[30],res[30],c=0;
	printf("enter how many bits \n");
	scanf("%d",&dn);
	printf("enter the %d data bits:",dn);
	for(i=0;i<dn;i++)
	{	
		scanf("%d",&data[i]);
	}
	printf("enter length of generator polynomial\n");
	scanf("%d",&gn);
	printf("enter the %d generator bits:",gn);
	for(i=0;i<gn;i++)
	{	
		scanf("%d",&gen[i]);
	}
	for(i=dn;i<(gn+dn-1);i++)
	{
		data[i]=0;
	}
	for(i=0;i<(gn+dn-1);i++)
	{
		printf("%d",data[i]);
	}
	printf("\n");
	for(cnt=0;cnt<gn;cnt++)
	{
		r[cnt]=data[cnt];
	}
	while(cnt<gn+dn)
	{
		while(r[0]==0)
		{
			if(cnt==gn+dn-1)
			{
				break;
			}
			for(i=0;i<gn-1;i++)
			{
				r[i]=r[i+1];
			}
			r[gn-1]=data[cnt++];
			
		}
		if(r[0]==0)
		{
			break;
		}
		for(j=0;j<gn;j++)
		{
			r[j]=r[j]^gen[j];
		}
	}
	printf("CRC bits are :");
	for(i=0;i<gn;i++)
	{
		printf("%d",r[i]);
	}
	j=1;
	for(i=dn;i<(gn+dn-1);i++)
	{
		data[i]=r[j++];
	}
	printf("\ntransmitting bits are:");
	for(i=0;i<(dn+gn-1);i++)
	{
		printf("%d",data[i]);
	}
	//for recevier side now
	printf("\n");
	printf("received bits are ");
	for(i=0;i<(gn+dn-1);i++)
	{
		scanf("%d",&res[i]);
	}
	for(cnt=0;cnt<gn;cnt++)
	{
		r[cnt]=res[cnt];
	}
	while(cnt<gn+dn)
	{
		while(r[0]==0)
		{
			if(cnt==gn+dn-1)
			{
				break;
			}
			for(i=0;i<gn;i++)
			{	
				r[i]=r[i+1];
			}
			r[gn-1]=res[cnt++];
		}
		if(r[0]==0)
		{
			break;
		}
		for(j=0;j<gn;j++)
		{
			r[j]=r[j]^gen[j];
		}
	}
	printf("CRC bits are :");
	for(i=0;i<gn;i++)
	{
		printf("%d",r[i]);
	}
	printf("\n");
	for(i=0;i<gn;i++)
	{
		if(r[i]==0)
		{
			c++;
		}	
	}
	if(c==gn)
	{
		printf("correct\n");
	}
	else
	printf("incorrect\n");
}
