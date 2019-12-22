#ifndef STACKSTRING_H_
#define STACKSTRING_H_
#include<string.h>
char stack[50][50];
int top1=-1;
char data[50];
int is_empty()
{
	if(top1==-1)
		return 1;
	else
		return 0;
}
int is_full()
{
	if(top1==49)
		return 1;
	else
		return 0;
}
void push1(char item[20])
{
	if(!is_full())
	{
		top1++;
		strcpy(stack[top1],item);
	}
	else
		printf("The stack is full!!");
}
char* pop1()
{	strcpy(data,stack[top1]);
	top1--;
	return data;
}


#endif /* STACKSTRING_H_ */
