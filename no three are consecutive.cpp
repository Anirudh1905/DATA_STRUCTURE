// C++ program to find the maximum sum such that
// no three are consecutive using recursion.
#include<bits/stdc++.h>
using namespace std;

int a[] = {100, 1000, 100, 1000, 1};
int sum[10000];

// Returns maximum subsequence sum such that no three
// elements are consecutive
int maxSumWO3Consec(int n)
{
	if(n==-1)    return sum[n]=0;
	if(n==0)    return sum[n]=a[0];
	if(n==1)    return sum[n]=a[0]+a[1];
	if(sum[n]!=-1)  return sum[n];
	return sum[n]=max(max(maxSumWO3Consec(n-1),a[n]+maxSumWO3Consec(n-2)),a[n]+a[n-1]+maxSumWO3Consec(n-3));
}

// Driver code
int main()
{
	
	int n = sizeof(a) / sizeof(a[0]);
	memset(sum,-1,sizeof(sum));
	cout << maxSumWO3Consec(n);

// this code is contributed by Kushdeep Mittal
	return 0;
}
