#include <bits/stdc++.h>

using namespace std;

int main()
{int n=4,m=5;
    int a[4][5] = 
    { 
        {1, 2, 1, 4, 8}, 
        {3, 7, 8, 5, 1}, 
        {8, 7, 7, 3, 1}, 
        {8, 1, 2, 7, 9}, 
    };
    unordered_map<int,int>mp;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mp[a[i][j]]==i)
                mp[a[i][j]]++;
        }
    }
    for(auto x:mp)
    {
        if(x.second==n)
            cout<<x.first<<" ";
    }
    return 0;
}
