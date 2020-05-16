#include<iostream>
using namespace std;
#include<cmath>
#include<stdlib.h>
class treenode
{
    int data;
    treenode *left;
    treenode *right;
    friend class tree;
};
class stack
{
	int top;
	treenode *data[30];
	public:
	stack()
	{
		top=-1;
	}
	void push(treenode *temp)
	{
		if(top!=29)
		{
			top=top+1;
			data[top]=temp;
			
		}
	}
	treenode* pop()
	{
		treenode *temp;
		if(top!=-1)
		{
			temp=data[top];
			top=top-1;
			return temp;
		}
	}
	int empty()
	{
		if(top==-1)
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}
	friend class tree;	
};

class tree
{
    treenode *root;
    char ch1;
    public:
    void create()
    {
        root = new treenode();
        cout<< "enter the data for root node"<<endl;
        cin>>root->data;
        root->left=root->right=NULL;
        do
        {
        create(root);
        cout<<"do you want to continoue ?"<<endl;
        cin>>ch1;
        } while (ch1=='Y' || ch1=='y');
    }
    
    
    void create(treenode *root)
    {
        treenode *curr;
        char ch;
        cout<<"enter the position left / right at which you want to insert a element"<<endl;
        cin>>ch;
        if(ch=='l' || ch=='L')
        {
          if(root->left==NULL)
          {
              curr = new treenode();
              cin>>curr->data;
              curr->left=curr->right=NULL;
              root->left=curr;
          }
          else
          {
              create(root->left);
          }
            
        }
        else if(ch=='r' || ch=='R')
        {
            if(root->right==NULL)
            {
                curr = new treenode();
                cin>>curr->data;
                curr->right=curr->left=NULL;
                root->right=curr;
            }
            else
            {
                create(root->right);
            }
            
        }
    }
    void inorder()
    {
        inorder(root);
    }
    void inorder(treenode *temp)
    {
       if(temp!=NULL)
       {
           inorder(temp->left);
           cout<<temp->data<<" ";
           inorder(temp->right);
       } 
    }
    tree()
    {
	root=NULL;
    }
    void preorder()
    {
    	preorder(root);
    }
    void preorder(treenode *temp)
    {
    	if(temp!=NULL)
    	{
    		cout<<temp->data<<" ";
    		preorder(temp->left);
    		preorder(temp->right);
    	}
    }
    void postorder()
    {
    	postorder(root);
    }
    void postorder(treenode *temp)
    {
    	if(temp!=NULL)
    	{
    		postorder(temp->left);
    		postorder(temp->right);
    		cout<<temp->data<<" ";
    	}
    }
    void create_nr()
    {
    	treenode *temp,*curr;
    	char c,c1;
    	int flag;
    	if(root==NULL)
    	{
    		root=new treenode();
    		cout<<"enter the data for the root node"<<endl;
    		cin>>root->data;
    	}
    	do{
    		temp=root;
    		flag=0;
    		curr=new treenode();
    		cin>>curr->data;
    		while(flag==0)
    		{
    			cout<<"enter the choice l/r wher you want to insert the data"<<endl;
    			cin>>c;
    			if(c=='l' || c=='L')
    			{
    				if(temp->left==NULL)
    				{
    					temp->left=curr;
    					flag=1;
    				}
    				else
    				{
    					temp=temp->left;
    				}
    				
    			}
    			else
    			{
    				if(temp->right==NULL)
    				{
    					temp->right=curr;
    					flag=1;
    				}
    				else
    				{
    					temp=temp->right;
    				}
    			}
    		}
    	cout<<"do you want to insert more node"<<endl;
    	cin>>c1;
    	}while(c1=='y' || c1=='Y');
    }
    void inorder_nr()
    {
    	treenode *temp;
    	stack s;
    	temp=root;
    	while(1)
    	{
    		while(temp!=NULL)
    		{
    			s.push(temp);
    			temp=temp->left;
    		}
    		if(s.empty())
    		{
    			break;
    		}
    		temp=s.pop();
    		cout<<temp->data<<" ";
    		temp=temp->right;
    	}
        cout<<endl;
    }
    void preoder_nr()
    {
        treenode *temp;
        stack s;
        temp=root;
        while(1)
        {
            while(temp!=NULL)
            {
                cout<<temp->data<<" ";
                s.push(temp);
                temp=temp->left;
            }
            if(s.empty())
            {
                break;
            }
            temp=s.pop();
            temp=temp->right;
        }
        cout<<endl;
    }
};


int main()
{
    int ch,c;
    tree t;
    do{
    cout<<"enter the options below :\n1.create binary tree using recursion \n2.display binary tree using recursion \n3.create binary tree without recursion \n4.display binary tree without recursion \n5.exit";
    cin>>ch;
    switch(ch)
    {
    case 1:
    t.create();
    break;
    case 2:
    cout<<"in order :";
    t.inorder();
    cout<<endl;
    cout<<"pre order:";
    t.preorder();
    cout<<endl;
    cout<<"post order";
    t.postorder();
    cout<<endl;
    break;
    case 3:
    t.create_nr();
    break;
    case 4:
    t.inorder_nr();
    t.preoder_nr();
    break;
    }}while(ch!=5);
return 0;

}
