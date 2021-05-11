// CPP program to find number of subarrays having
// product less than k.
#include <bits/stdc++.h>
using namespace std;

// Function to count numbers of such subsequences
// having product less than k.
int productSubSeqCount(vector<int> &a, int k)
{
	int n = a.size();
	int dp[k + 1][n + 1];
	memset(dp, 0, sizeof(dp));
    for(int i=1;i<=k;i++)
    {
        for(int j=1;j<=n;j++)
        {
            dp[i][j]=dp[i][j-1];
            if(a[j-1]<=i && a[j-1]>0)
                dp[i][j]+=(dp[i/a[j-1]][j-1]+1);
        }
    }
	return dp[k][n];
}

// Driver code
int main()
{
	vector<int> A;
	A.push_back(1);
	A.push_back(2);
	A.push_back(3);
	A.push_back(4);
	int k = 6;
	cout << productSubSeqCount(A, k) << endl;
}
