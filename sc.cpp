/*DIVYANG BAGLA
DIV-D
PD-38
ASS3
D3*/
#include<iostream>
#include<string.h>
#include<math.h>
#include<limits.h>
using namespace std;
class process{            //class process containing process and all times
    string pname;
    int arr_time;
    int burst_time;
    int wait_time;
    int turnar_time;
    int comp_time;
    public:
    friend class scehdule;
    
};
class scehdule{
    process p[100],p1[100];
    public:
    void fcfs_cal()          //fumction for fcfs 
    {
        int n,ct;
        float sum_avg=0.0,sum_turn=0.0;
        cout<<"Enter the total no. of process"<<endl;
        cin>>n;               // accepting the no of processes
        cout<<"Enter the name , arrival time and burst for"<<n<<"process"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter the name , arrival time and burst for"<<i+1<<"process:";
            cin>>p[i].pname>>p[i].arr_time>>p[i].burst_time;
        }
        for(int i=0;i<n;i++)
        {
            if(i==0)
            {
            p[i].comp_time = p[i].arr_time+p[i].burst_time;     //calculating the completion tme for 0th process
            ct = p[i].comp_time;
            }
            else
            {
                p[i].comp_time = p[i-1].comp_time+p[i].burst_time;
            }
        }
        for(int i=0;i<n;i++)
        {
            p[i].turnar_time = p[i].comp_time - p[i].arr_time;
            p[i].wait_time = p[i].turnar_time - p[i].burst_time;
        }
        for(int i=0;i<n;i++)
        {
            sum_avg = sum_avg + p[i].wait_time;              // sum of waiting times
            sum_turn = sum_turn + p[i].turnar_time;           //sum of turn around times 
        }
        cout<<"The average waiting time is :"<<sum_avg/n<<endl;
        cout<<"The average turnaround time is :"<<sum_turn/n<<endl;
    }
    void sjf_cal()            //function for shortest job first 
    {
        int n,ct;
        int rem_t[100];
        int sum_bur = 0;
        float sum_avg=0.0,sum_turn=0.0;
        int count = 0;
        cout<<"Enter the total no. of process"<<endl;
        cin>>n;
        cout<<"Enter the name , arrival time and burst for"<<n<<"process"<<endl;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter the name , arrival time and burst for"<<i+1<<"process:";
            cin>>p1[i].pname>>p1[i].arr_time>>p1[i].burst_time;
        }
        for(int i=0;i<n;i++)
        {
            rem_t[i] = p1[i].burst_time;
        }
        int t=0;
        int minm = INT_MAX;
        int check = 1;
        int shortest = 0;
        int finish_t =0;
        while(count!=n) //using this we calculated the waiting time 
        {
            for(int j=0;j<n;j++)
            {
                if(p1[j].arr_time <=t && (rem_t[j] < minm) && rem_t[j] > 0)
                {
                    minm = rem_t[j];
                    shortest = j;
                    check = 0;
                }
            }
            if(check==1)
            {
                t++;
                continue;
            }
            rem_t[shortest]--;
            minm = rem_t[shortest];
            if(minm==0)
                minm= INT_MAX;
            if(rem_t[shortest]==0)       //if the some process executed completely i.e burst time becomes zero
            {
                count++;
                check = 1;
                finish_t = t+1;
                p1[shortest].wait_time = finish_t - p1[shortest].burst_time - p1[shortest].arr_time;
                if(p1[shortest].wait_time < 0)
                    p1[shortest].wait_time = 0;
            }
             
            t++;                     //incrementing the time t
        }
        for(int i =0;i<n;i++)
        {
            p1[i].turnar_time = p1[i].wait_time + p1[i].burst_time;
        }
        for(int i=0;i<n;i++)
        {
            sum_avg = sum_avg + p1[i].wait_time;
            sum_turn = sum_turn + p1[i].turnar_time;
        }
        cout<<"The average waiting time is :"<<sum_avg/n<<endl;
        cout<<"The average turnaround time is :"<<sum_turn/n<<endl;
    }
};
int main()
{
    scehdule s;
    int choice;
    do{
        cout<<"Enter the choice below :\n1. FCFS \n2. SJF \n3.Exit \n";
        cin>>choice;
        switch(choice)
        {
            case 1:
            s.fcfs_cal();
            break;
            case 2:
            s.sjf_cal();
            break;
            case 3:
            exit(0);
            break;
        }
    }while(choice!=3);
return 0;
}

/*
OUTPUT:
Enter the choice below :
1. FCFS
2. SJF
3.Exit
1
Enter the total no. of process
4
Enter the name , arrival time and burst for4process
Enter the name , arrival time and burst for1process:P0
0
7
Enter the name , arrival time and burst for2process:P1
2
4
Enter the name , arrival time and burst for3process:P2
4
1
Enter the name , arrival time and burst for4process:P3
5
4
The average waiting time is :4.75
The average turnaround time is :8.75
Enter the choice below :
1. FCFS
2. SJF
3.Exit
2
Enter the total no. of process
4
Enter the name , arrival time and burst for4process
Enter the name , arrival time and burst for1process:P1
0
7
Enter the name , arrival time and burst for2process:P2
2
4
Enter the name , arrival time and burst for3process:P3
4
1
Enter the name , arrival time and burst for4process:P4
5
4
The average waiting time is :3
The average turnaround time is :7
Enter the choice below :
1. FCFS
2. SJF
3.Exit
3
*/