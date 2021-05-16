// C++ program to find winner of game
// if player can pick 1, x, y coins
#include <bits/stdc++.h>
using namespace std;

int dp[101];
int s(int x, int y, int w,int f,int a,int b)
{
	if(w<=0)
	{
	    if(f)
	        return 0;
	    else
	        return 1;
	}
	if(dp[w]!=-1)   return dp[w];
	if(x<=w)
	{
	    if(f==0)
	        return dp[w]=s(x,y,w-x,1,a+x,b);
	    else
	        return dp[w]=s(x,y,w-x,0,a,b+x);
	}
	if(y<=w)
	{
	    if(f==0)
	        return dp[w]=s(x,y,w-y,1,a+y,b);
	    else
	        return dp[w]=s(x,y,w-y,0,a,b+y);
	}
    if(f==0)
        return dp[w]=s(x,y,w-1,1,a+1,b);
	return dp[w]=s(x,y,w-1,0,a,b+1);
}

// Driver program to test findWinner();
int main()
{
	int x = 3, y = 4, n = 5;
	memset(dp,-1,sizeof(dp));
	if (!s(x, y, n,0,0,0))
		cout << 'A';
	else
		cout << 'B';

	return 0;
}
