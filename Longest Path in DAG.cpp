#include <bits/stdc++.h>
using namespace std;
void topo(int src,vector<bool>&vis,stack<int>&st,vector<vector<pair<int,int>>>g)
{
    vis[src]=1;
    for(auto x:g[src])
    {
        if(!vis[x.first])
            topo(x.first,vis,st,g);
    }
    st.push(src);
}
int main()
{
    int v,e,src;cin>>v>>e>>src;
    vector<vector<pair<int,int>>>g(v);
    for(int i=0;i<e;i++)
    {
        int x,y,w;
        cin>>x>>y>>w;
        g[x].push_back({y,w});
    }
    vector<bool>vis(v,0);stack<int>st;
    for(int i=0;i<v;i++)
    {
        if(!vis[i])
            topo(i,vis,st,g);
    }
    vector<int>d(v,INT_MIN);
    d[src]=0;
    while(!st.empty())
    {
        int y=st.top();st.pop();
        if(d[y]!=INT_MIN)
        {
            for(auto x:g[y])
            {
                int u=d[y],w=x.second,v=d[x.first];
                if(u+w>v)
                    d[x.first]=u+w;
            }
        }    
    }
    for(int i=0;i<v;i++)
    {
        if(i!=src && d[i]!=INT_MIN)
        {
            cout<<src<<" "<<i<<" "<<d[i]<<endl;
        }
    }
    // 6 7     IP                                                                                               
    // 1                                                                                                      
    // 0 1 5                                                                                                  
    // 1 5 5                                                                                                  
    // 5 3 2                                                                                                  
    // 3 2 20                                                                                                 
    // 4 2 10                                                                                                 
    // 5 2 50                                                                                                 
    // 1 4 2  
    return 0;
}
