

int isempty(int top)
{
	if(top==-1)
		return 0;
	else
		return 1;

}
int isfull(int top)
{
	if(top==19)
		return 0;
	else
		return 1;
}
void push(char a[20],int *t,char n)
{
		
		*t=*t+1;
		a[*t]=n;
		
}
int pop(char a[20],int *t)
{
	
	char temp;
	temp=a[*t];
	*t=*t-1;
	return temp;

}
void display(char a[20],int t)
{
	int i;
	for(i=t;i>=0;i--)
	{
		printf("%c\n",a[i]);
	}
}
int topele(char a[20],int t)
{
	return a[t];
}
