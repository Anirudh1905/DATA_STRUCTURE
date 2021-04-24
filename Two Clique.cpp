#include<bits/stdc++.h>
using namespace std;
bool bipartite(int src,int par,vector<int>g[],int c,vector<int>&color)
{
    color[src]=c;
    for(auto x:g[src])
    {
        if(!color[x])
            return bipartite(x,src,g,3-c,color);
        else if(x!=par && color[x]==c)
            return false;
    }
    return true;
}
int main()
{
	int v,e;cin>>v>>e;vector<int>g[v];
	for(int i=0;i<v;i++)
	{
	    int x,y;cin>>x>>y;
	    g[x].push_back(y);
	    g[y].push_back(x);
	}vector<int>grev[v];
	vector<int>dummy(v,0);vector<int>color(v,0);
	for(int i=0;i<v;i++)
	{
	    vector<int>dummy(v,0);
	    dummy[i]=1;
	    for(auto x: g[i])
	        dummy[x]=1;
	    for(int j=0;j<v;j++)
	    {
	        if(dummy[j]==0) 
	        {
	            grev[i].push_back(j);
	            //grev[j].push_back(i);
	        }
	    }
	}
// 	for(int i=0;i<v;i++)
// 	{   cout<<i<<" ";
// 	    for(auto x:grev[i])
// 	        cout<<x<<" ";
// 	    cout<<endl;
// 	}
	!bipartite(0,0,grev,1,color)?cout<<"Not Possible":cout<<"Two Clique";
// 	IP
// 	5 5
//  0 1
//  1 2
//  2 0
//  0 3
//  3 4
	return 0;
}
