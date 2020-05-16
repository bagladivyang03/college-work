/*DIVYANG BAGLA
PANEL : D
ROLL NO. : PD-38
BATCH : D3
*/
#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<cmath>
using namespace std;
class node{
    string word;
    string meaning;
    node *left;
    node *right;
    friend class dict;
    friend class queue;
    friend class stack;
};
class stack{                                 //stack class for copy non recursive 
    int top;
    node *dat[100];
    public:
    stack(){
        top=-1;
    }
    void push(node *temp)                    //for pushing of elements 
    {
        if(top!=99)
        {
            top += 1;
            dat[top]=temp;
        }
    }
    node *pop()                          //for popout the element
    {
        if(top!=-1)
        {
            node *temp;
            temp = dat[top];
            top = top -1;
            return temp;
        }
    }
    int isempty()                           //to check if stack is empty
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
    friend class dict;                     
};
class queue                   //queue class for bfs and mirror image functions 
{
    int front;
    int rear;
    node *data[100];
    friend class dict;
    public:
    queue()
    {
        front = -1;
        rear = -1;
    }
    int isempty()
    {
        if(front==rear)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    void enqueue(node *temp)
    {
        if(rear!=99)
        {
            rear++;
            data[rear]=temp;
        }
    }
    node *dequeue()
    {
        if(!isempty())
        {
            node *temp;
            front++;
            temp = data[front];
            return temp;
        }
    }

};
class dict{
    node *root,*root1;;
    public:
    dict()                           //constructor for dict class 
    {
        root=NULL;
    }
    void create()              //create non recursive bst      
    {
        node *curr,*temp;
        char ch;
        if(root==NULL)              //if root null allocate memory for root
        {
            root = new node();
            cout<<"enter the word";
            cin>>root->word;
            cin.ignore();
            cout<<"enter the meaning";
            getline(cin,root->meaning);
            root->left=root->right=NULL;
        }
        do
        {
            
            temp=root;
            curr = new node();                                // allocating memory for new nodes 
            cout<<"enter the word to inserted in a tree";
            cin>>curr->word;
            cin.ignore();
            cout<<"enter the meaning to be inserted in a tree";
            getline(cin,curr->meaning);
            curr->left=curr->right=NULL;
            int flag = 0;
            while(flag ==0)
            {
                if((curr->word).compare(temp->word)<0)              //if root word is larger than entered word then in the left side insert nodes
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
                else if((curr->word).compare(temp->word)>0)
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
                else
                {
                    cout<<"word already exits"<<endl;
                    flag=1;
                }
            }
            cout<<"Do you want to insert more nodes ?"<<endl;
            cin>>ch;
        } while (ch=='y' || ch=='Y');
    }
    void inorder_rec()                   //display bst using inorder recursive 
    {
        inorder_rec(root);
    }
    void inorder_rec(node *temp)
    {
        if(temp!=NULL)
        {
            inorder_rec(temp->left);
            cout<<"word:"<<temp->word<<" ";
            cout<<"meaning :"<<temp->meaning<<" ";
            inorder_rec(temp->right);
            
        }
        //cout<<"\n";
    }
    void insert_d()                     //insert a word in the dictionary
    {
        insert_d(root);
    }
    void insert_d(node *temp)                  
    {
        string wordy,meaningy;
        node *nnode;
        nnode=  new node();
        cout<<"Enter the word";
        cin>>nnode->word;
        cin.ignore();
        cout<<"Enter the meaning";
        getline(cin,nnode->meaning);
        nnode->left=nnode->right=NULL;
        int flag=0;
        while(flag==0)
        {
            if((nnode->word).compare(temp->word)<0)
            {
                if(temp->left==NULL)
                {
                    temp->left=nnode;
                    flag=1;
                }
                else
                {
                    temp=temp->left;
                }
            }
            else if((nnode->word).compare(temp->word)>0)
            {
                if(temp->right==NULL)
                {
                    temp->right=nnode;
                    flag=1;
                }
                else{
                    temp=temp->right;
                }
            }
            else
            {
                cout<<"Word already present in the dictionary"<<endl;
                flag=1;
            }
        }
    }
    void mirror_nr()                             //mirror non recursive function
    {
        node *temp;
        queue q;
        temp=root;
        q.enqueue(temp);
        while(!q.isempty())
        {
            temp=q.dequeue();
            node *temp1;
            temp1 = temp->left;
            temp->left = temp->right;
            temp->right = temp1;
            if(temp->left!=NULL)
            {
                q.enqueue(temp->left);
            }
            if(temp->right!=NULL)
            {
                q.enqueue(temp->right);
            }
        }
        bfs();
    }
    void mirror_rec()
    {
        mirror_rec(root);

    }
    void mirror_rec(node *temp)
    {
        node *temp1;
        temp1= temp->left;
        temp->left=temp->right;
        temp->right=temp1;
        if(temp->left!=NULL)
        {
            mirror_rec(temp->left);
        }
        if(temp->right!=NULL)
        {
            mirror_rec(temp->right);
        }
    }
    void bfs()                                //display breadth first search
    {
        node *temp;
        queue q1;
        temp=root;
        q1.enqueue(temp);
        while(!q1.isempty())
        {
            temp = q1.dequeue();
            cout<<temp->word<<"\t";
            cout<<temp->meaning<<"\t";
            cout<<"\n";
            if(temp->left!=NULL)
            {
                q1.enqueue(temp->left);
            }
            if(temp->right!=NULL)
            {
                q1.enqueue(temp->right);
            }
        }
    }
    void copy_nr(dict d)                                       //copy non recursive function
    { 
        node *temp1,*temp2;
        stack s1,s2;
        
        root1=new node();
        root1->left=root1->right=NULL;
        temp2 = root1;
        temp1 = d.root;
        temp2->word=temp1->word;
        temp2->meaning=temp1->meaning;
        while(1)
        {
            while(temp1!=NULL)
            {
                if(temp1->left!=NULL)
                {
                    node *nnode = new node();
                    nnode->word=temp1->left->word;
                    nnode->meaning=temp1->left->meaning;
                    nnode->left=nnode->right=NULL;
                    temp2->left=nnode;
                }
                if(temp1->right!=NULL)
                {
                    node *nnode = new node();
                    nnode->word=temp1->right->word;
                    nnode->meaning=temp1->right->meaning;
                    nnode->left=nnode->right=NULL;
                    temp2->right=nnode;
                }
                s2.push(temp2);
                s1.push(temp1);
                temp1=temp1->left;
                temp2=temp2->left;
            }
            if(s1.isempty()==1)
            {
                break;
            }
            else
            {
                temp1=s1.pop();
                temp2=s2.pop();
                temp1=temp1->right;
                temp2=temp2->right;
            }
        }
        inorder_rec(root1);
        
    }
    void copy_rec()
    {
        node *t;
        t = copy_rec(root);
        inorder_rec(t);
    }
    node *copy_rec(node *root){
        node *temp;
        temp = NULL;
        temp = root;
        if(root!=NULL)
        {
            temp = new node();
            temp->word=root->word;
            temp->meaning=root->meaning;
            temp->left=copy_rec(root->left);
            temp->right=copy_rec(root->right);
        }
        return temp;
    }
    void delete_node()                     // delete a node from the tree
    {
        node *temp,*s;
        string wordy;
        cout<<"Enter the word to be deleted ?";
        cin>>wordy;
        node *curr,*par;
        curr = root;
        par = root;
        while((wordy).compare(curr->word)!=0 && curr!=NULL)
        {
            if((wordy).compare(curr->word)<0)
            {
                par=curr;
                curr=curr->left;
            }
            else if((wordy).compare(curr->word)>0){
                par=curr;
                curr=curr->right;
            }
        }
        if(curr==root)                      //deletion of a root node 
        {
            if(curr->left==NULL)
            {
                root=curr->right;
            }
            else if(curr->right==NULL)
            {
                root=curr->left;
            }
            else if(curr->left!=NULL && curr->right!=NULL){
                temp=curr->left;
                root=curr->right;
                s=curr->right;
                while(s->left!=NULL)
                {
                    s=s->left;
                }
                s->left=temp;
            }
            
        }
        else if(curr!=root)
        {
            if(curr->left==NULL && curr->right==NULL) //deletion of a leaf node
            {
                if(par->left==curr)
                {
                    par->left=NULL;
                }
                else
                {
                    par->right=NULL;
                }
            }
            else if(curr->left==NULL)            //deletion of a node with a single child
            {
                if(par->left==curr)
                {
                    par->left=curr->right;
                }
                else{
                    par->right=curr->right;
                }
            }
            else if(curr->right==NULL)           //deletion of node with a single child
            {
                if(par->left==curr)
                {
                    par->left=curr->left;
                }
                else{
                    par->right=curr->left;
                }
            }
            else                               //deletion of a node with a with two childs left and right 
            {                                     
                temp=curr->left;
                s=curr->right;
                while(s->left!=NULL)
                {
                    s=s->left;
                }
                s->left=temp;
                if(par->left==curr)
                {
                    par->left=curr->right;
                }
                else{
                    par->right=curr->right;
                }
            }
        }
        else{
            cout<<"invalid word!"<<endl;
        }
        if(curr!=NULL)
        {
            curr->left=NULL;
            curr->right=NULL;
            delete curr;
        }  
    }
};
int main()
{
    dict d,d1;                 // class dictionary objects
    int ch;
    do
    {
    cout<<"Enter the choice below \n1.create non-recursive \n2.insert \n3.delete a node \n4.mirror non-recursive \n5.display level-wise \n6.copy  non-recursive \n7.inorder recursive display \n8.copy Recursive \n9.mirror recursive \n10.exit \n";
    cin>>ch;
    switch(ch)
    {
        case 1:
        d.create();
        d.inorder_rec();
        cout<<endl;
        break;
        case 2:
        d.insert_d();
        cout<<endl;
        break;
        case 3:
        d.delete_node();
        d.inorder_rec();
        cout<<endl;
        break;
        case 4:
        d.mirror_nr();
        cout<<endl;
        break;
        case 5:
        d.bfs();
        cout<<endl;
        break;
        case 6:
        d1.copy_nr(d);
        cout<<endl;
        break;
        case 7:
        d.inorder_rec();
        cout<<endl;
        break;
        case 8:
        d.copy_rec();
        cout<<endl;
        break;
        case 9:
        d.mirror_rec();
        cout<<endl;
        break;
        case 10:
        exit(0);
        break;
    }
    }while(ch!=10);
}

/*output:-
Enter the choice below 
1.create non-recursive
2.insert
3.delete a node
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
1
enter the wordpencil
enter the meaningsharpner
enter the word to inserted in a treeeraser
enter the meaning to be inserted in a treeDo you want to insert more nodes ?
PS C:\Users\Divyang\Desktop\ds_progs> g++ -g as3.cpp -o as3.cpp.exe
PS C:\Users\Divyang\Desktop\ds_progs> .\as3.cpp.exe
Enter the choice below 
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
1
enter the wordpencil
enter the meaningstationery
enter the word to inserted in a treeeraser
enter the meaning to be inserted in a treestationery
Do you want to insert more nodes ?
y
enter the word to inserted in a treesharpner
enter the meaning to be inserted in a treestationery
Do you want to insert more nodes ?
n
word:eraser meaning :stationery word:pencil meaning :stationery word:sharpner meaning :stationery 
Enter the choice below 
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
1
enter the word to inserted in a treeduster
enter the meaning to be inserted in a treestationery
Do you want to insert more nodes ?
n
word:duster meaning :stationery word:eraser meaning :stationery word:pencil meaning :stationery word:sharpner meaning :stationery 
Enter the choice below
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
7
word:duster meaning :stationery word:eraser meaning :stationery word:pencil meaning :stationery word:sharpner meaning :stationery 
Enter the choice below 
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
5
pencil  stationery      
eraser  stationery      
sharpner        stationery
duster  stationery

Enter the choice below
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
6
word:duster meaning :stationery word:eraser meaning :stationery word:pencil meaning :stationery word:sharpner meaning :stationery 
Enter the choice below 
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
3
Enter the word to be deleted ?duster
word:eraser meaning :stationery word:pencil meaning :stationery word:sharpner meaning :stationery 
Enter the choice below
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
3
Enter the word to be deleted ?pencil
word:eraser meaning :stationery word:sharpner meaning :stationery 
Enter the choice below
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
9

Enter the choice below
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
4
sharpner        stationery      
eraser  stationery      

Enter the choice below
1.create non-recursive
2.insert
3.delete a node
4.mirror non-recursive
5.display level-wise
6.copy  non-recursive
7.inorder recursive display
8.copy Recursive
9.mirror recursive
10.exit
10
*/
