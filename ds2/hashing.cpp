#include<iostream>
#include<string.h>
#include<stdlib.h>
#define max 20
using namespace std;
class student{
    int roll_no;
    string name;
    char grade;
    public:
    student()
    {
        roll_no = -1;
        name = '\0';
        grade = '\0';

    }
    friend class hashing;
};
class hashing{
    student s[max],s1[max];
    public:
    hashing()
    {
        for(int i=0;i<max;i++)
        {
            s[i].roll_no = -1;
        }
    }
    void linear_without()
    {
        student curr;
        char ch = 'y';
        int index,i,flag=0;
        while(ch=='y')
        {
            cout<<"\nEnter the Roll No. of student: ";
            cin>>curr.roll_no;
            cout<<"\nEnter the name of the student: ";
            cin>>curr.name;
            cout<<"\nEnter the grade of student: ";
            cin>>curr.grade;
            index = curr.roll_no%max;
            if(s[index].roll_no==-1)
            {
                s[index] = curr;
            }
            else
            {
                i=1;
                i=(index+1)%max;
                while(i!=index)
                {
                    if(s[i].roll_no == -1)
                    {
                        s[i] = curr;
                        flag = 1;
                        break;
                    }
                    i=(i+1)%max;
                }
                if(flag==0)
                {
                    cout<<"Hash table is full \n";
                }
            }
            display_withoutrepl();
            cout<<"Do you want to add more records ?";
            cin>>ch;
        }
    }
    void linear_withrepl()
    {
        student curr,temp;
        int i,index,flag=0;
        char ch='y';
        while(ch=='y')
        {
            cout<<"\nEnter the Roll No. of student: ";
            cin>>curr.roll_no;
            cout<<"\nEnter the name of the student: ";
            cin>>curr.name;
            cout<<"\nEnter the grade of student: ";
            cin>>curr.grade;
            index = curr.roll_no%max;
            if(s1[index].roll_no == -1)
            {
                s1[index] = curr;
            }
            else{
                temp = curr;
                if(index != (s1[index].roll_no%max))
                {
                    temp = s1[index];
                    s1[index] = curr;
                }
                i=1;
                i = (index + 1)%max;
                while(i!=index)
                {
                    if(s1[i].roll_no == -1)
                    {
                        s1[i] = temp;
                        flag = 1;
                        break;
                    }
                }
                if(flag == 0)
                {
                    cout<<"\nHash table full";
                }
            }
            display_withrepl();
            cout<<"\nDo you want to continue ?";
            cin>>ch;
        }
    }
    void display_withoutrepl()
    {
        cout<<"\nThe student record's are as follow's: ";
        cout<<"\n\tROLL NO.\tNAME\tGRADE\n";
        for(int i=0;i<max;i++)
        {
            cout<<i<<"\t"<<s[i].roll_no<<"\t"<<s[i].name<<"\t"<<s[i].grade<<"\n";
        }
    }
    void display_withrepl()
    {
        cout<<"\nThe student record's are as follow's: ";
        cout<<"\n\tROLL NO.\tNAME\tGRADE\n";
        for(int i=0;i<max;i++)
        {
            cout<<i<<"\t"<<s1[i].roll_no<<"\t"<<s1[i].name<<"\t"<<s1[i].grade<<"\n";
        }
    }
};
int main()
{
    hashing h;
    int ch1;
    do{
    cout<<"Enter the options below: \n1.Linear Probing without Replacement \n2.Linear Probing with Replacement \n3.Display without replacement\n4..Display with replacement\n4.Exit \n ";
    cin>>ch1;
    switch(ch1)
    {
        case 1:
        h.linear_without();
        break;
        case 2:
        h.linear_withrepl();
        break;
        case 3:
        h.display_withoutrepl();
        break;
        case 4:
        h.display_withrepl();
        break;
        case 5:
        exit(0);
        break;
    }
    }while(ch1!=5);
}



