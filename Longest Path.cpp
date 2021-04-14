#include<bits/stdc++.h>
#define n 3
#define m 10
using namespace std;
bool valid(int dp[n][m],int i,int j)
{
    if(i<0 || i>=n || j<0 || j>=m)
        return false;
    if(dp[i][j]==0)
        return false;
    return true;
}
int ans=-1;
void solve(int dp[n][m],int i,int j,int c)
{
    if(i==1 && j==7) 
    {
        ans=max(ans,c);
        return;
    } 
    if(valid(dp,i-1,j))
    {
        dp[i-1][j]=0;
        solve(dp,i-1,j,c+1);
        dp[i-1][j]=1;
    }
    if(valid(dp,i,j-1))
    {
        dp[i][j-1]=0;
        solve(dp,i,j-1,c+1);
        dp[i][j-1]=1;
    }    
    if(valid(dp,i+1,j))
    {
        dp[i+1][j]=0;
        solve(dp,i+1,j,c+1);
        dp[i+1][j]=1;
    }    
    if(valid(dp,i,j+1))
    {
        dp[i][j+1]=0;
        solve(dp,i,j+1,c+1);
        dp[i][j+1]=1;
    }    
}
int main()
{
	int mat[n][m] =
    {
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
        { 1, 1, 0, 1, 1, 0, 1, 1, 0, 1 },
        { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 }
    };
	solve(mat,0,0,0);
	cout<<ans;
	return 0;
}
