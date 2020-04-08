
#define MAX 20
#include<stdio.h>
#include<bits/stdc++.h>
#include<string>
using namespace std;
class GraphPrim{
    int noofvertices;
    int mat[MAX][MAX];
    public:
    GraphPrim(){
        cout<<"enter the no. of vertices ";
        cin>>noofvertices;
        mat[noofvertices][noofvertices];
        for(int i=0;i<noofvertices;i++)
        {
            for(int j=0;j<noofvertices;j++)
            {
                mat[i][j]=INT_MAX;
            }
        }
    }
    void create()
    {
        char ch;
        for(int i=0;i<noofvertices;i++)
        {
            for(int j=0;j<noofvertices;j++)
            {
                if(mat[i][j]==INT_MAX)
                {
                    cout<<"Is"<<i<<"is a neighbour of "<<j<<"?";
                    
                    cin>>ch;
                    if(ch=='y' || ch=='Y')
                    {
                        cout<<"enter the cost";
                        cin>>mat[i][j];
                        mat[j][i]=mat[i][j];
                    }
                }
            }
        }
    }
    void display()
    {
        cout<<"Graph Display:\n";
        for(int i =0;i<noofvertices;i++)
        {
            for(int j=0;j<noofvertices;j++)
            {
                if(mat[i][j]!=INT_MAX)
                {
                    cout<<mat[i][j]<<"\t";
                }
                else
                {
                    cout<<"*\t";
                }
                
            }
            cout<<endl;
        }
    }
    void prim()
    {
        int stv;
        cout<<"enter the starting vertex";
        cin>>stv;
        int mincost = 0;
        int nearest[noofvertices];
        int t[noofvertices][2];
        nearest[stv]=-1;
        for(int i=0;i<noofvertices;i++)
        {
            if(i!=stv)
            {
                nearest[i]=stv;
            }
        }
        int r=0;
        int min ;
        int j;
        for(int i=0;i<noofvertices;i++)
        {
            min=INT_MAX;
            for(int k=0;k<noofvertices;k++)
            {
                if(nearest[k]!=-1 && mat[k][nearest[k]] < min)
                {
                    j=k;
                    min=mat[k][nearest[k]];
                }
            }
            t[r][0]=j;
            t[r][1]=nearest[j];
            r =r+1;
            mincost = mincost + mat[j][nearest[j]];
            nearest[j]=-1;
            for(int k=0;k<noofvertices;k++)
            {
                if(nearest[k]!=-1 && mat[k][nearest[k]] > mat[k][j])
                {
                    nearest[k] = j;
                }
            }
        }
        cout<<"MST VALUE :"<<mincost<<"\n";
        cout<<"the reaktions of edges of this tree is:\n";
        for(int i=0;i<r-1;i++)
        {
            for(int j=0;j<2;j++)
            {
                cout<<t[i][j]<<"\t";
            }
            cout<<endl;
        }
    }
};
int main()
{
    GraphPrim g;
    g.create();
    g.display();
    g.prim();
return 0;
}
