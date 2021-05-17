// A C++ program to find Largest rectangular
// sub-matrix whose sum is 0
#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
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
                ans=i-mp[s]+1;
                a=mp[s];b=i;
            }
        }
        mp[s]=i;
    }
    return {ans,{a,b}};
}

void sumZeroMatrix(int m[][MAX], int r, int c)
{
    int ans=INT_MIN,fup=0,fdown=0,fleft=0,fright=0;
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
	        //cout<<(j-i+1)*x.first<<endl;
	        if((j-i+1)*x.first>ans)
	        {
	            fup=i;fdown=j;fleft=x.second.first;fright=x.second.second;
	            ans=(j-i+1)*x.first;
	        }
	    }
	}
	cout<<ans<<endl;
	// Print final values
	for (int j = fup; j <= fdown; j++)
	{
		for (int i = fleft; i <= fright; i++)
			cout << m[j][i] << " ";
		cout << endl;
	}
}

// Driver program to test above functions
int main()
{
	int a[][MAX] = { { 9, 7, 16, 5 }, { 1, -6, -7, 3 },
					{ 1, 8, 7, 9 }, { 7, -2, 0, 10 } };

	int row = 4, col = 4;
	sumZeroMatrix(a, row, col);
	return 0;
}
