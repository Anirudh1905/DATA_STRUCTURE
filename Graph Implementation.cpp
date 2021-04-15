#include <bits/stdc++.h>
using namespace std;
void adjacency_list(vector<int>g[7],int v,int e)
{
    for(int i=0;i<e;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=1;i<=v;i++)       //for printing
    {
        cout<<i<<"-> ";
        for(int j=0;j<g[i].size();j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }
}
void adjacency_matrix(int g[7][7],int v,int e)
{
    for(int i=1;i<=v;i++)
    {
        int x,y;cin>>x>>y;
        g[x][y]=1;
        g[y][x]=1;
    }
    for(int i=1;i<=v;i++)       //for printing
    {
        for(int j=0;j<v;j++)
            cout<<g[i][j]<<" ";
        cout<<endl;
    }
}
int main()
{
    int v,e;cin>>v>>e;
    vector<int>g1[v+1];
    int g2[7][7]={0};
    adjacency_list(g1,v,e);
    adjacency_matrix(g2,v,e);
    return 0;
}
