#include<iostream>
#include<ctime>
#include<stdlib.h>
using namespace std;
int main()
{
	int nf,ws,i=1,j;
	int ctr=0;
	cout<<"enter the no of frames";
	cin>>nf;
	cout<<"enter the window size";
	cin>>ws;
	
	while(i<=nf)
	{
		int x=0;
		for(int j=i;j<i+ws && j<=nf;j++)
		{
			cout<<"sent frame is"<<j<<endl;
			ctr++;
		}
		for(int j=i;j<i+ws && j<=nf;j++)
		{
			int flag=rand()%2;
			//cout<<flag<<endl;
			if(flag!=1)
			{	
				cout<<"Acknowledgement for frame"<<j<<endl;
				x++;
			}	
			else
			{
				cout<<"frame "<<j<<" not received"<<endl;
				cout<<"retransmitting window"<<endl;
				break;
			}
		}
	cout<<endl;
	i+=x;
	}
	cout<<"total no. of transmissions"<<ctr<<endl;
return 0;
}
