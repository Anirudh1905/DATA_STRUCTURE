// A C++ program to find Largest rectangular
// sub-matrix whose sum is 0
#include <bits/stdc++.h>
using namespace std;
#define MAX_ROW 10
#define MAX_COL 10

pair<int,pair<int,int>> subsum(int arr[],int n)
{
    unordered_map<int,int>mp;int a,b,s=0,ans=INT_MIN;
    for(int i=0;i<n;i++)
    {
        s+=arr[i];
        if(s==0)
        {
            if(ans<i+1)
            {
                ans=i+1;
                a=0;b=i;
            }
        }
        else if(mp.find(s)!=mp.end())
        {
            if(ans<i-mp[s])
            {
                ans=i-mp[s];
                a=mp[s]+1;b=i;
            }
        }
        else
            mp[s]=i;
    }
    return {ans,{a,b}};
}

void sumZeroMatrix(int m[][MAX_COL], int r, int c)
{
    int ans=INT_MIN,fup=0,fdown=0,fleft=0,fright=0;
    for(int i=0;i<r;i++)
        for(int j=0;j<c;j++)
            if(m[i][j]==0)
                m[i][j]=-1;
	for(int i=0;i<r;i++)
	{
	    int a[c];memset(a,0,sizeof(a));
	    for(int j=i;j<r;j++)
	    {
	        for(int k=0;k<c;k++)
	        {
	           a[k]+=m[j][k]; 
	        }
	        auto x=subsum(a,c);
	        if((j-i+1)*(x.first)>ans)
	        {
	            fup=i;fdown=j;fleft=x.second.first;fright=x.second.second;
	            ans=(j-i+1)*(x.first);
	        }
	    }
	}
	cout<<ans<<endl;
	cout<<"("<<fup<<","<<fleft<<") ("<<fdown<<","<<fright<<")";
}

// Driver program to test above functions
// for finding max sum comment that 0 conversion to -1
int main()
{
	int a[MAX_ROW][MAX_COL] = { {0, 0, 1, 1},
                                    {0, 1, 1, 0},
                                    {1, 1, 1, 0},
                                  {1, 0, 0, 1} };    
    int row = 4, col = 4;
	sumZeroMatrix(a, row, col);
	return 0;
}
