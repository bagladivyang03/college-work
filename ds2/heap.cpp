#include<iostream>
#define max 20
using namespace std;
class heap{
    int marks[max+1];
    int n;
    public:
    heap()
    {
        cout<<"Enter the no. of students:";
        cin>>n;
        marks[n+1];
        for(int i=0;i<n+1;i++)
        {
            marks[i] = 0;
        }
    }
    void max_heap()
    {
        char ch;
        int j=n;
        int m,i=1;
        do{
            cout<<"Enter the marks of student "<<i<<":";
            cin>>m;
            marks[i]=m;
            insert_max(i);
            i++;
            j--;
        }while(j>=1);
        disp();
        cout<<"Maximum Marks:"<<marks[1]<<endl;
    }
    void insert_max(int i)
    {
        int elem = marks[i];
        while((i>1) && (marks[i/2]<elem))
        {
            marks[i] = marks[i/2];
            i = i/2;
        }
        marks[i]=elem;
    }
    void min_heap()
    {
        int j=n;
        int m,i=1;
        do{
            cout<<"Enter the marks of student"<<i<<":";
            cin>>m;
            marks[i] = m;
            insert_min(i);
            i++;
            j--;
        }while(j>=1);
        disp();
        cout<<"Minimum Marks:"<<marks[1]<<endl;
    }
    void insert_min(int i)
    {
        int elem = marks[i];
        while((i > 1) && (marks[i/2] > elem))
        {
            marks[i] = marks[i/2];
            i = i/2;
        }
        marks[i] = elem;
    }
    void disp()
    {
        for(int i=1;i<n+1;i++)
        {
            cout<<marks[i]<<"\t";
        }
        cout<<"\n";
    } 
};
int main()
{
    heap h;
    //h.max_heap();
    h.min_heap();
}

