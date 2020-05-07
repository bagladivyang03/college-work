#include<iostream>
using namespace std;
int main()
{
    int n,m;
    char ch = 'A';
    cout<<"Enter the no. of processes :";
    cin>>n;
    cout<<"Enter the no of type of resources :";
    cin>>m;
    int alloc[n][m],max[n][m],need[n][m];
    int avail[m];
    cout<<"Enter the data for allocation : \n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>alloc[i][j];
        }
    }
    cout<<"Entered data for allocation is \n";
    for(int i=0;i<m;i++)
    {
        cout<<ch<<"\t";
        ch += 1;

    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<alloc[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Enter the data for max :\n";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>max[i][j];
        }
    }
    cout<<"Entered data for max is :\n";
    for(int i=0;i<m;i++)
    {
        cout<<ch<<"\t";
        ch += 1;

    }
    cout<<endl;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<max[i][j]<<"\t";
        }
        cout<<"\n";
    }
    cout<<"Enter the data for available :";
    for(int i=0;i<m;i++){
        cin>>avail[i];
    }
    int f[n],ans[n];
    int ind=0;
    for(int k=0;k<n;k++)
    {
        f[k]=0;
    }
    for (int i = 0; i < n; i++) { 
        for (int j = 0; j < m; j++) 
            need[i][j] = max[i][j] - alloc[i][j]; 
    }
    int y= 0;
    int d=0;
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            if(f[i]==0)
            {
            int flag = 0;
            for(int j=0;j<m;j++)
            {
                if(need[i][j]> avail[j])
                {
                    flag = 1;
                    break;
                }
            }
            if(flag==0){
                ans[ind++] = i;
                
                for(y=0;y<m;y++)
                {
                    avail[y] = avail[y] + alloc[i][y];
                }
                f[i]=1;
            }
            }
        }  
   }
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<ans[i]<<"\t";
    }
    cout<<endl;
}