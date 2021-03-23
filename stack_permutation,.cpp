// Given two arrays, check if one array is 
// stack permutation of other. 
#include<bits/stdc++.h> 
using namespace std; 

// function to check if input queue is 
// permutable to output queue 
bool checkStackPermutation(int input[], int output[], int n) 
{ 
    queue<int>ip,op;stack<int>tmp;
	for(int i=0;i<n;i++)     ip.push(input[i]);
	for(int i=0;i<n;i++)     op.push(output[i]);
	while(!ip.empty())
	{
	    int x=ip.front();ip.pop();
	    if(x==op.front())
	    {
	        op.pop();
	        while(!op.empty() && !tmp.empty())
	        {
	            if(tmp.top()==op.front())
	            {
	                op.pop();
	                tmp.pop();  
	            }
	            else 
	                break;
	        }
	    }
	    else
	        tmp.push(x);
	}
	return (ip.empty()&&tmp.empty());
} 

// Driver program to test above function 
int main() 
{ 
	// Input Queue 
	int input[] = {1, 2, 3}; 

	// Output Queue 
	int output[] = {3,2,1}; 

	int n = 3; 

	if (checkStackPermutation(input, output, n)) 
		cout << "Yes"; 
	else
		cout << "Not Possible"; 
	return 0; 
} 
