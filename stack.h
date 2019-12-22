#ifndef STACK_H_
#define STACK_H_
int top=-1;
char a[20];
int isempty()
{
	if(top==-1)
		return 0;
	else
		return 1;

}
int isfull()
{
	if(top==19)
		return 0;
	else
		return 1;
}
void push(char n)
{
		
		top=top+1;
		a[top]=n;
		
}
char pop()
{
	
	char temp;
	temp=a[top];
	top=top-1;
	return temp;

}
void display()
{
	int i;
	for(i=top;i>=0;i--)
	{
		printf("%c\n",a[i]);
	}
}
int topele()
{
	return a[top];
}

#endif

