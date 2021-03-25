// C++ program to find sum of all minimum and maximum
// elements Of Sub-array Size k.
#include<bits/stdc++.h>
using namespace std;

// Returns sum of min and max element of all subarrays
// of size k
int SumOfKsubArray(int a[] , int n , int k)
{
	deque<int>s,g;int sum=0;
	for(int i=0;i<n;i++)
	{
	    if(!s.empty() && s.front()==i-k)
	        s.pop_front();
	    if(!g.empty() && g.front()==i-k)
	        g.pop_front();
	    while(!s.empty() && a[s.back()]>=a[i])
	        s.pop_back();
	    while(!g.empty() && a[g.back()]<=a[i])
	        g.pop_back();
	    s.push_back(i);
	    g.push_back(i);
	    if(i>=k-1)
	        sum+=(a[g.front()]+a[s.front()]);
	}
	return sum;
}

// Driver program to test above functions
int main()
{
	int arr[] = {2, 5, -1, 7, -3, -1, -2} ;
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 3;
	//cout<<INT_MAX+INT_MAX;
	cout << SumOfKsubArray(arr, n, k) ;
	return 0;
}
