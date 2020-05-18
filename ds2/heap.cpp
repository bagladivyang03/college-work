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
    int ch;
    do{
        cout<<"Enter the choice below :\n1.MAX heap \n2.MIN heap \n3.EXIT\n";
        cin>>ch;
        switch(ch)
        {
            case 1:
            h.max_heap();
            break;
            case 2:
            h.min_heap();
            break;
            case 3:
            exit(0);
        }
    }while(ch!=3);
}

/*
OUTPUT:-
Enter the no. of students:10
Enter the choice below :
1.MAX heap
2.MIN heap
3.EXIT
1
Enter the marks of student 1:90
Enter the marks of student 2:88
Enter the marks of student 3:76
Enter the marks of student 4:54
Enter the marks of student 5:45
Enter the marks of student 6:12
Enter the marks of student 7:34
Enter the marks of student 8:54
Enter the marks of student 9:99
Enter the marks of student 10:100
100     99      76      88      90      12      34      54      54      45      
Maximum Marks:100
Enter the choice below :
1.MAX heap
2.MIN heap
3.EXIT
2
Enter the marks of student1:100
Enter the marks of student2:12
Enter the marks of student3:13
Enter the marks of student4:14
Enter the marks of student5:55
Enter the marks of student6:6
Enter the marks of student7:22
Enter the marks of student8:34
Enter the marks of student9:11
Enter the marks of student10:10
6       10      12      14      11      13      22      100     34      55
Minimum Marks:6
Enter the choice below :
1.MAX heap
2.MIN heap
3.EXIT
3
*/


