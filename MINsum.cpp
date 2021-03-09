// CPP program to find minimum number of 
// elements such that their sum is greater 
// than sum of remaining elements of the array. 
#include <bits/stdc++.h> 
#include <string.h> 
using namespace std; 

// function to find minimum elements needed. 
int minElements(int a[], int n) 
{ 
	sort(a,a+n);
	int dp[n],sum=0,i=0;
    for(i=0;i<n;i++)
    {
        sum+=a[i];
        dp[i]=sum;
    }sum=0;
    for(i=n-1;i>=0;i--)
    {
        sum+=a[i];
        if(sum>dp[i-1])
            break;
    }
    return n-i;
} 

// Driver function 
int main() 
{ 
	int arr[] = {9,4,6,3,1,7,1,1,5}; 
	int n = sizeof(arr) / sizeof(arr[0]); 
	cout << minElements(arr, n) << endl; 
	return 0; 
} 
