#include<iostream>
using namespace std;
#include<cmath>
#include<stdlib.h>
class node
{
    int coeff;
    int exp;
    node *next;
    friend class poly;
};
class poly
{
    node *head;
    public:
    void createpoly()
    {
        int ch;
        node *temp;
        temp=head;
        do{
            node *nnode;
            nnode=new node;
            cout<<"enter the coefficient :"<<endl;
            cin>>nnode->coeff;
            cout<<"enter the exponent :"<<endl;
            cin>>nnode->exp;
            temp->next=nnode;
            nnode->next=head;
            temp=nnode;
            cout<<"Do you want to continue :"<<endl;
            cout<<"enter the choice 1. Yes"<<endl;
            cin>>ch;
        }while(ch==1);
    }
    void displaypoly()
    {
        node *temp;
        temp=head->next;
        while(temp->exp!=-1)
        {
            if(temp->next->exp==-1)
            {
                cout<<temp->coeff<<"X^("<<temp->exp<<")";

            }
            else
            {
                cout<<temp->coeff<<"X^("<<temp->exp<<")+";
            }
            temp=temp->next;
            
        }
    }
    void addpoly(poly p1,poly p2)
    {
        node *t1,*t2,*t3,*nnode;
        t1=p1.head->next;
        t2=p2.head->next;
        t3=head;
        while(t1->exp!=-1 || t2->exp!=-1)
        {
            nnode=new node;
            if(t1->exp==t2->exp)
            {
                nnode->coeff=t1->coeff+t2->coeff;
                nnode->exp=t1->exp;
                t1=t1->next;
                t2=t2->next;
                t3->next=nnode;
                nnode->next=head;
                t3=nnode;
            }
            else if(t1->exp > t2->exp)
            {
                nnode->coeff=t1->coeff;
                nnode->exp=t1->exp;
                t3->next=nnode;
                nnode->next=head;
                t3=nnode;
                t1=t1->next;
            }
            else
            {
                nnode->coeff=t2->coeff;
                nnode->exp=t2->exp;
                t3->next=nnode;
                nnode->next=head;
                t3=nnode;
                t2=t2->next;
            }
            
        }
    }
    void evalpoly(int a)
    {
        int sum=0;
        node *temp;
        temp=head->next;
        while(temp!=head)
        {
            sum=sum+(temp->coeff*pow(a,temp->exp));
            temp=temp->next;
        }
        cout<<sum;
    }
    poly()
    {
        head=new node();
        head->coeff=0;
        head->exp=-1;
        head->next=head;
    }
};

int main()
{
    int a;
    poly p1,p2,p3;
    cout<<"make the 1st polynomial :"<<endl;
    p1.createpoly();
    p1.displaypoly();
    cout<<endl;
    cout<<"make the 2nd polynomial :"<<endl;
    p2.createpoly();
    p2.displaypoly();
    cout<<endl;
    p3.addpoly(p1,p2);
    p3.displaypoly();
    cout<<endl;
    p3.evalpoly();

}
