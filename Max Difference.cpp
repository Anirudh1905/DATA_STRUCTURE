// CPP implementation of 
// above algorithm 
#include <bits/stdc++.h> 
using namespace std; 

int MaxSumDifference(int a[], int n) 
{ 
	sort(a,a+n);
	vector<int>v;
	
	for(int i=0;i<n/2;i++)
	{
	    v.push_back(a[i]);
	    v.push_back(a[n-i-1]);
	}
	if(n%2)
	    v.push_back(a[n/2]);
	int sum=(v[n-1]-v[0]);
	for(int i=1;i<v.size();i++)
	{
	    sum+=abs(v[i-1]-v[i]);
	}
	return sum;
} 

// Driver function 
int main() 
{ 
	int a[] = { 1, 2, 3, 4, 5 }; 
	int n = sizeof(a) / sizeof(a[0]); 

	cout << MaxSumDifference(a, n) << endl; 
} 
