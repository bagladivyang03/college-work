#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "stack1.h"
int isp(char ch)
{
	if(ch=='^')
	{
		return 3;
	}
	else if(ch=='*' || ch=='/')
	{
		return 2;
	}
	else if(ch=='+' || ch=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int isp_pre(char ch)
{
	if(ch=='^')
	{
		return 4;
	}
	else if(ch=='*' || ch=='/')
	{
		return 2;
	}
	else if(ch=='+' || ch=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
int icp(char ch)
{
	if(ch=='^')
	{
		return 4;
	}
	else if(ch=='*' || ch=='/')
	{
		return 2;
	}
	else if(ch=='+' || ch=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}
int icp_pre(char ch)
{
	if(ch=='^')
	{
		return 3;
	}
	else if(ch=='*' || ch=='/')
	{
		return 2;
	}
	else if(ch=='+' || ch=='-')
	{
		return 1;
	}
	else
	{
		return 0;
	}	
}

void in_post(char infix[20],char out[20])
{
	int i=0,j=0,len;
	char a[20];
	int top=-1;
	len=strlen(infix);
	printf("%d\n",len);
	for(i=0;i<=len;i++)
	{
		if(infix[i]=='\0')
		{
			while(isempty(top)==1)
			{
				out[j]=pop(a,&top);
				j++;
				//printf("%c",out[j]);
			}
		}
		else if(isalnum(infix[i]))
		{
				out[j]=infix[i];
				j++;
				//printf("%c",out[j]);
		}
		else if(infix[i]==')')
		{
			while(topele(a,top)!='(')
			{
				out[j]=pop(a,&top);
				j++;
			}
			pop(a,&top);
		}
		else
		{
				if(infix[i]=='(')
				{
					push(a,&top,infix[i]);
				}
				//else if(isempty(top)==0)
				//{
				//	push(a,&top,infix[i]);
				//}
				
				else
				{
					while(isp(topele(a,top)) >= icp(infix[i]))
					{
					out[j]=pop(a,&top);
					j++;	
					if(isempty(top)==0)
					{
						break;
					}
						
					}
				push(a,&top,infix[i]);
				}
		}
			
		
	}
	out[j]='\0';
}
void in_pre(char infix[50],char pre_p[50])
{
	char a[20],pre[50];
	int top=-1,len,k,len1;
	int i=0,j=0;
	len=strlen(infix);
	for(i=len-1;i>=0;i--)
	{
		
		if(isalnum(infix[i]))
		{	
			pre[j]=infix[i];
			j++;
		}
		else if(infix[i]=='(')
		{
			while(topele(a,top)!=')')
			{
				pre[j]=pop(a,&top);
				j++;
			}
			pop(a,&top);
		}
		else 
		{
			if(infix[i]==')')
			{
				push(a,&top,infix[i]);
			}
			else 
			{
				while(isp_pre(topele(a,top)) >= icp_pre(infix[i]))
				{
					pre[j]=pop(a,&top);
					j++;
					if(isempty(top)==0)
					{
						break;
					}
					push(a,&top,infix[i]);
				}
			}
		}
		
		
	}
	while(isempty(top)==1)
	{
		pre[j]=pop(a,&top);
		j++;
	}
	pre[j]='\0';
	k=0;
	len1=strlen(pre);
	for(j=len1-1;j>=0;j--)
	{
		pre_p[k]=pre[j];
		k++;
	}
	pre_p[k]='\0';
}
int main()
{
	char in[50],out[50],pre_p[50],pre[50],infix[50];
	int j,ch;
	printf("enter the string u want to enter \n");
	scanf("%s",in);
	printf("enter the string u want to enter \n");
	scanf("%s",infix);
	do
	{
		printf("enter the choice below \n1.infix to postfix \n2.infix to prefix \n3.exit \n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1:
			in_post(in,out);
			for(j=0;out[j]!='\0';j++)
			{
				printf("%c",out[j]);
			}
			break;
			case 2:
			in_pre(infix,pre_p);
			for(j=0;pre_p[j]='\0';j++)
			{
				printf("%c",pre_p[j]);
			}			
			break;
				
		}
	}while(ch!=3);

	return 0;

}
