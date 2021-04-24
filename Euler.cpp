#include <bits/stdc++.h>
using namespace std;
void DFS(int src,vector<bool>&vis,vector<int>g[])
{
    vis[src]=1;
    for(auto x:g[src])
        if(!vis[x])
            DFS(x,vis,g);
}
bool connected_graph(vector<int>g[],int v)
{
    vector<bool>vis(v+1,0);
    int node=-1;
    for(int i=0;i<v;i++)
    {
        if(g[i].size()>0)
        {
            node=i;
            break;
        }
    }
    //cout<<node;
    if(node==-1)    return true;
    DFS(node,vis,g);
    for(int i=0;i<v;i++)
        if(!vis[i] && g[i].size()>0)
            return false;
    return true;
}
int main()
{
    int v,e;cin>>v>>e;vector<int>g[v+1];
    for(int i=0;i<e;i++)
    {
        int x,y;cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    for(int i=0;i<v;i++)
    {
        cout<<i<<" ";
        for(auto x:g[i])
            cout<<x<<" ";
        cout<<endl;
    }
    int odd=0;
    for(int i=0;i<v;i++)
    {
        if(g[i].size() &1)
            odd++;
    }
    //cout<<connected_graph(g,v);
    if(!connected_graph(g,v))
        cout<<"Not Possible";
    else
    {
        for(auto x:ans)
            cout<<x<<" ";
    }
    return 0;
}
