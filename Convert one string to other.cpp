#include<bits/stdc++.h> 
using namespace std; 
 
int minOps(string& A, string& B) 
{ 
	int n=A.length(),m=B.length();
	int mp[256]={0};
	for(int i=0;i<n;i++)    mp[A[i]]++;
	for(int i=0;i<m;i++)    mp[B[i]]--;
	for(int i=0;i<256;i++)
	    if(mp[i]!=0)
	        return 0;
	int i=n-1,j=m-1,ans=0;
	while(i>=0 && j>=0)
	{
	   if(A[i]==B[j])
	   {
	       i--;j--;
	   }
	   else
	   {
	       while(A[i]!=B[j] && i>=0)
	       {
	           i--;ans++;
	       }
	   }
	}
	return ans;
} 

// Driver program 
int main() 
{ 
	string A = "ABCD"; 
	string B = "BCAD"; 
	cout << "Minimum number of operations "
			"required is " << minOps(A, B); 
	return 0; 
} 
