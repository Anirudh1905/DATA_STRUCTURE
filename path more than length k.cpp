#include <bits/stdc++.h>
using namespace std;
bool solve(int src,int k,vector<bool>&vis,vector<pair<int,int>>g[])
{
    vis[src]=1;
    if(k<=0)    return true;
    for(auto x:g[src])
    {
        int u=x.first,w=x.second;
        if(!vis[u])
        {
            if(w>=k)    return true;
            if(solve(u,k-w,vis,g))  return true;
        }
    }
    vis[src]=0;
    return false;
}
int main()
{
    int v,e,src,k;cin>>v>>e>>src>>k;vector<bool>vis(v+1,0);
    vector<pair<int,int>>g[v+1];
    for(int i=0;i<e;i++)
    {
        int x,y,w;cin>>x>>y>>w;
        g[x].push_back({y,w});
        g[y].push_back({x,w});
    }
    cout<<solve(src,k,vis,g);
    // IP
    // 10 11 1 23 
    // 1 2 1
    // 2 3 2
    // 3 4 2
    // 2 5 5
    // 5 6 2
    // 6 7 1
    // 4 7 3
    // 7 10 2
    // 9 10 1
    // 4 8 4
    // 8 9 5
    
    // OP
    // 1
    return 0;
}
