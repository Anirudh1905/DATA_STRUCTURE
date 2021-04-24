#include <bits/stdc++.h>
using namespace std;

int main()
{
    int v,e,dest;cin>>v>>e>>dest;
    vector<pair<int,int>>g[v];
    vector<int>d(v,INT_MAX);d[0]=0;
    for(int i=0;i<v;i++)
    {
        int x,y;
        cin>>x>>y;
        g[x].push_back({y,0});
        g[y].push_back({x,1});
    }
    for(int i=0;i<v;i++)
    {   
        if(d[i]!=INT_MAX)
        {
            for(auto x: g[i])
            {
                int w=x.second,u=d[i],v=d[x.first];
                if(u+w<v)
                    d[x.first]=u+w;
            }
        }
    }
    cout<<d[dest];
    // IP
    // 7 7 6
    // 0 1
    // 2 1
    // 2 3
    // 5 1
    // 4 5
    // 6 4
    // 6 3
    
    // OP
    // 2
    return 0;
}
