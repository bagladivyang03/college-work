#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include "stack.h"
#include "stackstring.h"
void in_post(char in[20],char post[20]);
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
void in_post(char in[20],char post[20])
{
	//char a[50];
	//int top=-1;
	int i=0,j=0;
	int len=strlen(in);
	for(i=0;i<=len;i++)
	{
		if(in[i]=='\0')
		{
			while(isempty()==1)
			{
				post[j]=pop();
				j++;
			}
		}
		else if(isalnum(in[i]))
		{
			post[j]=in[i];
			j++;
		}
		else if(in[i]==')')
		{
			while(topele()!='(')
			{
				post[j]=pop();
				j++;
			}
			pop();
		}
		else
		{
			if(in[i]=='(')
			{
				push(in[i]);
			}
			else
			{
				while(isp(topele()) >= icp(in[i]))
				{
					post[j]=pop();
					j++;
					if(isempty()==0)
					{
						break;
					
					}
				}
				push(in[i]);
			}
		}
	}
	post[j]='\0';
}
void post_in(char pos[20],char pre[20])
{
	int j;
	char op1[30],op2[30],res[30],res1[30],str[30];
	int len=strlen(pos);
	for(int i=0;i<=len;i++)
	{
		if(isalnum(pos[i]))
		{
			res1[0]=pos[i];
			res1[1]='\0';
			push1(res1);	
		}
		else if(pos[i]=='+' || pos[i]=='-' || pos[i]=='*' || pos[i]=='/' || pos[i]=='^')
		{
			strcpy(op1,pop1());
			strcpy(op2,pop1());
        		str[0]='(';//start making expression
			str[1]='\0';

			strcat(str,op2);// get (a

			int l=strlen(str);
			str[l]=pos[i];//add operator, .: get (a+
			str[l+1]='\0';
			strcat(str,op1);//.: get (a+b

			l=strlen(str);
			str[l]=')';//.: get (a+b)
			str[l+1]='\0';
			//top++;
			push1(str);//push (a+b)
		}
		
	}
	strcpy(pre,pop1());
	
	
}
int main()
{
	char in[20],post[20];
	char pos[20],pre[20];
	int ch;
	do
	{
	printf("enter the choice below \n1.infix to postfix \n2.postfix to infix \n3.exit \n");
	scanf("%d",&ch);
	switch(ch)
	{
	case 1:
	printf("enter the infix expression :");
	scanf("%s",in);
	in_post(in,post);
	printf("the postfix expression is :");
	printf("%s\n",post);
	break;
	case 2:
	printf("enter the postfix expression :");
	scanf("%s",pos);
	post_in(pos,pre);
	printf("the infix expression is :");
	printf("%s\n",pre);
	break;
	}
	}while(ch!=3);
return 0;
}



/*
OUTPUT:
enter the choice below 
1.infix to postfix 
2.postfix to infix 
3.exit 
1
enter the infix expression :(A+B^C)*D+E^5
the postfix expression is :ABC^+D*E5^+
enter the choice below 
1.infix to postfix 
2.postfix to infix 
3.exit 
2   
enter the postfix expression :ABC^+D*E5^+
the infix expression is :(((A+(B^C))*D)+(E^5))
enter the choice below 
1.infix to postfix 
2.postfix to infix 
3.exit 
1
enter the infix expression :A^B^C
the postfix expression is :ABC^^
enter the choice below 
1.infix to postfix 
2.postfix to infix 
3.exit 
2
enter the postfix expression :ABC^^
the infix expression is :(A^(B^C))
enter the choice below 
1.infix to postfix 
2.postfix to infix 
3.exit 
3
*/
