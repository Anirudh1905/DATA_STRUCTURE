// C++ program to Print all possible paths from
// top left to bottom right of a mXn matrix
#include<bits/stdc++.h>
using namespace std;
bool valid(vector<vector<int>>dp,int i,int j,int n,int m)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    return true;
}
void solve(vector<vector<int>>dp,int i,int j,int n,int m,vector<int>&tmp)
{
    if(i==n-1 && j==m-1)
    {
        for(auto x:tmp)
            cout<<x<<" ";
        cout<<endl;
        return;
    } 
    if(valid(dp,i+1,j,n,m))
    {
        tmp.push_back(dp[i+1][j]);
        solve(dp,i+1,j,n,m,tmp);
        tmp.pop_back();
    }
    if(valid(dp,i,j+1,n,m))
    {
        tmp.push_back(dp[i][j+1]);
        solve(dp,i,j+1,n,m,tmp);
        tmp.pop_back();
    }
}
int main()
{
	vector<vector<int>> mat{ { 1, 2, 3 },
                              { 4, 5, 6 },
                              { 7, 8, 9 } };
	vector<int>tmp;tmp.push_back(1);
	solve(mat,0,0,3,3,tmp);
	return 0;
}
