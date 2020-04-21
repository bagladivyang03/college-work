#include<iostream>
using namespace std;
#include<stdlib.h>
class tbtnode{
    int data;
    int leftb;
    int rightb;
    tbtnode *left;
    tbtnode *right;
    
    friend class tbt;
    public:
    tbtnode()
    {
        leftb =1;
        rightb=1;
    }
};
class tbt{
    tbtnode *head;
    public:
    tbt(){
        head = new tbtnode();
        head->rightb=0;
        head->left=head;
        head->right=head;
    }
    void create(){
        tbtnode *root,*curr,*temp;
        int flag;
        char ch,ch1;
        root =new tbtnode();
        head->leftb =0;
        cout<<"enter the data for root node";
        cin>>root->data;
        head->left=root;
        root->left=root->right=head;
        do{
            temp=root;
            flag=0;
            curr = new tbtnode();
            cout<<"enter the data for tree";
            cin>>curr->data;
            while(flag==0){
                cout<<"enter the side l/r";
                cin>>ch;
                if(ch=='l' || ch=='L'){
                    if(temp->leftb==1){
                        curr->right=temp;
                        curr->left=temp->left;
                        temp->left=curr;
                        temp->leftb=0;
                        flag=1;
                    }
                    else{
                        temp=temp->left;
                    }
                }
                else if(ch=='r' || ch=='R'){
                    if(temp->rightb==1){
                        curr->left=temp;
                        curr->right=temp->right;
                        temp->right=curr;
                        temp->rightb=0;
                        flag=1;
                    }
                    else{
                        temp=temp->right;
                    }
                }
            }
        cout<<"Do you want to add more nodes ?";
        cin>>ch1;
        }while(ch1=='y' ||ch1=='Y');
    }
    void inorder(){
        tbtnode *temp;
        temp=head;
        while(1){
            temp=inordersucc(temp);
            if(temp==head)
            break;
            cout<<temp->data<<" ";
        }
    }
    tbtnode *inordersucc(tbtnode *temp){
        tbtnode *x;
        x=temp->right;
        if(temp->rightb==0){
            while(x->leftb==0){
                x=x->left;
            }
        }
        return x;
    }
    void preorder()
    {
        tbtnode *temp;
        temp = head->left;
        while(temp!=head)
        {
            cout<<temp->data<<" ";
            while(temp->leftb!=1)
            {
                temp=temp->left;
                cout<<temp->data<<" ";
            }
            while(temp->rightb==1)
            {
                temp=temp->right;
            }
            temp=temp->right;
        }
    }
};
int main(){
    tbt t;
    int ch;
    do{
        cout<<"enter the choice below:\n1.Create the Threaded Binary Tree\n2.Inorder traversal \n3.Preorder Traversal \n4.Exit \n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            t.create();
            break;
            case 2:
            t.inorder();
            cout<<"\n";
            break;
            case 3:
            t.preorder();
            cout<<"\n";
            break;
            case 4:
            exit(0);
            break;
        }
    }while(ch!=4);
}
