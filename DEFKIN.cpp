#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;cin>>t;
    while(t--)
    {
        int n,m,a,b,q,mx=INT_MIN,my=mx;cin>>n>>m>>q;vector<int>x,y;
        x.push_back(0);
        y.push_back(0);
    	for(int i=0;i<q;i++)
    	{
    		cin>>a>>b;
    		x.push_back(a);
    		y.push_back(b);
    	}
    	x.push_back(n+1);
    	y.push_back(m+1);
    	sort(x.begin(),x.end());
    	sort(y.begin(),y.end());
    	for(int i=1;i<x.size();i++)
    	{
    		if((x[i]-x[i-1]-1)>mx)
    			mx=(x[i]-x[i-1]-1);
    		if((y[i]-y[i-1]-1)>my)
    			my=(y[i]-y[i-1]-1);
    	}
    	cout<<mx*my<<endl;
    }
	return 0;
}
