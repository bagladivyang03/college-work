#include<iostream>
using namespace std;
class gnode{
    int id;
    string name;
    gnode *next;
    public:
    gnode()
    {
        id = 0;
        name = '\0';
        next = NULL;
    }
    friend class graph;
    friend class stack;
    friend class queue;
};
class stack{
    int top;
    int stck[20];
    public:
    stack()
    {
        top=-1;
    }
    int isfull()
    {
        if(top!=19){
            return 1;
        }
        else{
            return 0;
        }
    }
    int isempty()
    {
        if(top==-1){
            return 0;
        }
        else{
            return 1;
        }
    }
    void push(int v){
        if(isfull()==1)
        {
            top++;
            stck[top]=v;
        }
    }
    int pop(){
        int s1;
        if(isempty()==1){
            s1=stck[top];
            top--;
            return s1;
        }
    }
    friend class graph;
};
class queue{
    int front,rear;
    int q[20];
    public:
    queue()
    {
        front=-1;
        rear=-1;
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
    void enqueue(int v)
    {
        if(rear!=19)
        {
            rear++;
            q[rear]=v;
        }
    }
    int dequeue()
    {
        int temp;
        if(isempty()==0)
        {
            front++;
            temp=q[front];
            return temp;
        }
    }
    friend class graph;

};
class graph{
    int n;
    gnode *head[10];
    public:
    graph()
    {
        n=0;
        cout<<"Enter the no of friends";
        cin>>n;
        for(int i=0;i<n;i++)
        {
            head[i]=new gnode();
            head[i]->id=i;
            cout<<"Enter the name of id "<<i<<":";
            cin>>head[i]->name;
        }
    }
    void create();
    void dfs_r();
    void dfs_r(int,int *);
    void dfs_nr(int);
    void bfs_nr(int);
};
void graph :: create()
{
    gnode *curr,*temp;
    int f_id;
    char ch;
    for(int i=0;i<n;i++)
    {
        temp = head[i];
        cout<<"--------------------------------"<<endl;
        cout<<"Enter the friends of "<<head[i]->name<<":"<<endl;
        do{
            cout<<"Enter the ID :"<<endl;
            cin>>f_id;
            if(f_id==head[i]->id){
                cout<<"You cannot be your own friends !!!"<<endl;
            }
            else{
                curr =  new gnode();
                curr->id =f_id;
                curr->name = head[f_id]->name;
                temp->next=curr;
                temp=temp->next;
            }
            cout<<"Do you want to add for friends of"<<head[i]->name<<endl;
            cin>>ch;
        }while(ch=='y' || ch=='Y');
    }
}
void graph :: dfs_r()
{
    int user[10];
    int s_id;
    for(int i=0;i<n;i++)
    {
        user[i]=0;
    }
    cout<<"Enter the index of starting vertex :";
    cin>>s_id;
    dfs_r(s_id,user);
    cout<<endl;
}
void graph :: dfs_r(int v,int user[10])
{
    cout<<head[v]->name<<"\t";
    user[v]=1;
    gnode *temp = head[v]->next;
    while(temp!=NULL)
    {
        if(!user[temp->id])
        {
            dfs_r(temp->id,user);
        }
        temp=temp->next;
    }
}
void graph :: dfs_nr(int s_v)
{
    int user[10];
    for(int i=0;i<n;i++)
    {
        user[i]=0;
    }
    stack s;
    s.push(s_v);
    user[s_v]=1;
    do{
        s_v = s.pop();
        cout<<head[s_v]->name<<"\t";
        gnode *temp = head[s_v]->next;
        while(temp!=NULL)
        {
            if(!user[temp->id])
            {
                s.push(temp->id);
                user[temp->id]=1;
                break;
            }
            temp=temp->next;
        }
    }while(s.isempty()==1);
    cout<<endl;
}
void graph :: bfs_nr(int v)
{
    int user[10];
    for(int i=0;i<n;i++)
    {
       user[i]=0;
    }
    queue q1;
    q1.enqueue(v);
    user[v]=1;
    while(q1.isempty()==0)
    {
        v=q1.dequeue();
        cout<<head[v]->name<<"\t";
        gnode *temp = head[v]->next;
        while(temp!=NULL)
        {
            if(!user[temp->id])
            {
                q1.enqueue(temp->id);
                user[temp->id]=1;
            }
            temp=temp->next;
        }
    }
    cout<<endl;
}
int main()
{
    graph g;
    int s_v;
    g.create();
    //g.dfs_r();
    cout<<"Enter the starting vertex";
    cin>>s_v;
    //g.dfs_nr(s_v);
    g.bfs_nr(s_v);

}
