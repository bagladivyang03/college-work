#include<stdio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
};
typedef struct node sll;


void create(sll *head)
{
	int n,ele;
	sll *curr,*nnode;
	printf("enter the no. of nodes you want to insert in a list\n");
	scanf("%d",&n);
	curr=head;
	do
	{
		nnode=(sll *)malloc(sizeof(sll));
		printf("enter the element\n");
		scanf("%d",&ele);
		nnode->data=ele;
		nnode->next=NULL;
		curr->next=nnode;
		curr=nnode;
		n--;
	}while(n>0);

		
}

int length(sll *head)
{
	sll *curr;
	int k=0;
	curr=head;
	while(curr->next!=NULL)	
	{
		k++;
		curr=curr->next;
	}
	return k;
}

void display(sll *head)
{
	sll *curr;
	curr=head->next;
	while(curr!=NULL)
	{
		printf("%p\t",curr);
		printf("%d\t",curr->data);
		printf("%p\t",curr->next);
		curr=curr->next;
		printf("\n");
	}
}
void insert(sll *head)
{
	sll *curr,*nnode;
	int data,pos,k1,i=1;
	nnode=(sll *)malloc(sizeof(sll));
	printf("enter the position at which u want to insert the element \n");
	scanf("%d",&pos);
	printf("enter the element\n");
	scanf("%d",&data);
	k1=length(head);
	//printf("%d",k1);
	curr=head;
	if(pos>k1+1)
	{
		printf("element cant be inserted \n");
	}
	else
	{
		while(curr!=NULL && i<pos)
		{
			i++;
			curr=curr->next;
			
		}
		nnode->next=curr->next;
		curr->next=nnode;
		nnode->data=data;
	}
}

void delete(sll *head)
{
	sll *prev,*curr,*temp;
	int pos,i=1;
	printf("enter the position at which u want to delete the element\n");
	scanf("%d",&pos);
	prev=head;
	curr=head->next;
	int k3=length(head);
	if(pos>k3+1)
	{
		printf("data cannot be deleted \n");
	}
	else
	{
		while(curr!=NULL && i<pos)
		{
			i++;
			prev=curr;
			curr=curr->next;
		}
		temp=curr;
		prev->next=curr->next;
		curr->next=NULL;
		free(temp);
	}
}

void reverse(sll *head)
{
	sll *prev,*curr,*temp;
	prev=NULL;
	curr=head->next;
	while(curr!=NULL)
	{
		temp=curr->next;
		curr->next=prev;
		prev=curr;
		curr=temp;
	}
	head->next=prev;
}
void sort(sll *head)
{
	sll *prev,*temp,*curr;
	
	int k4=length(head);
	for(int i=0;i<k4;i++)
	{
		prev=head;
		curr=head->next;
		for(int j=0;j<k4-i-1;j++)
		{
			temp=curr->next;
			if(curr->data > temp->data)
			{
				prev->next=temp;
				curr->next=temp->next;
				temp->next=curr;	
				prev=temp;
			}
			else
			{
				prev=curr;
				curr=curr->next;
			}
		}
	}
}

void merge(sll *head1,sll *head2)
{
	sll *curr1,*curr2,*temp;
	int flag;
	curr1=head1->next;
	curr2=head2->next;
	if(curr1->data < curr2->data)
	{
		temp=head1;
		flag=1;
	} 
	else
	{
		temp=head2;
		flag=0;
	}
	while(curr1!=NULL && curr2!=NULL)
	{
		if(curr1->data < curr2->data)
		{
			temp->next=curr1;
			temp=curr1;
			curr1=curr1->next;
		}
		else
		{
			temp->next=curr2;
			temp=curr2;
			curr2=curr2->next;
		}
	}
	if(curr1==NULL)
	{
		temp->next=curr2;
	}
	if(curr2==NULL)
	{
		temp->next=curr1;
	}
	if(flag==1)
	{
		display(head1);
	}
	else
	{
		display(head2);
	}
}


int main()
{
	sll *head,*head1,*head2;
	head=(sll *)malloc(sizeof(sll));
	head1=(sll *)malloc(sizeof(sll));
	head2=(sll *)malloc(sizeof(sll));
	head->next=NULL;
	int ch;
	do
	{
	printf("enter the choice below \n1.insert nodes \n2.display nodes \n3. insert a node \n4.delete a node \n5.reverse \n6.sort a linked list \n7.merge two lists \n8.exit \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:
			create(head);
			break;
		case 2:
			display(head);
			break;
		case 3:
			insert(head);
			break;
		case 4:
			delete(head);
			break;
		case 5:
			reverse(head);	
			break;
		case 6:
			sort(head);
			break;
		case 7:
			create(head1);
			sort(head1);	
			create(head2);
			sort(head2);
			merge(head1,head2);
			break;
	}
	}while(ch!=8);
	
}
