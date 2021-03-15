// A C++ program to demonstrate implementation of k stacks in a single 
// array in time and space efficient way 
#include<bits/stdc++.h> 
using namespace std; 

// A C++ class to represent k stacks in a single array of size n 
class kStacks 
{ 
	int *arr,*top,*next,n,k,free;
	public:
	kStacks(int k,int n);
	bool isFull()   {return free==-1;}
	void push(int item,int sn);
	int pop(int sn);
	bool isEmpty(int sn)    {return top[sn]==-1;}
}; 

//constructor to create k stacks in an array of size n 
kStacks::kStacks(int k1, int n1) 
{ 
	int k=k1,n=n1;
	arr=new int[n];
	top=new int [k];
	next=new int[n];
	for(int i=0;i<n;i++)    next[i]=i+1;
	next[n-1]=-1;
	free=0;
	for(int i=0;i<k;i++)    top[i]=-1;
} 

// To push an item in stack number 'sn' where sn is from 0 to k-1 
void kStacks::push(int item, int sn) 
{ 
	if(isFull())
	{
	    cout<<"Overflow"<<endl;return;
	}
	int i=free;
	free=next[i];
	next[i]=top[sn];
	top[sn]=i;
	arr[i]=item;
} 

// To pop an from stack number 'sn' where sn is from 0 to k-1 
int kStacks::pop(int sn) 
{ 
	if(isEmpty(sn))
	{
	    cout<<"Underflow"<<endl;return INT_MAX;
	}
	int i=top[sn];
	top[sn]=next[i];
	next[i]=free;
	free=i;
	return arr[i];
} 

/* Driver program to test twStacks class */
int main() 
{ 
	// Let us create 3 stacks in an array of size 10 
	int k = 3, n = 10; 
	kStacks ks(k, n); 

	// Let us put some items in stack number 2 
	ks.push(15, 2); 
	ks.push(45, 2); 

	// Let us put some items in stack number 1 
	ks.push(17, 1); 
	ks.push(49, 1); 
	ks.push(39, 1); 

	// Let us put some items in stack number 0 
	ks.push(11, 0); 
	ks.push(9, 0); 
	ks.push(7, 0); 

	cout << "Popped element from stack 2 is " << ks.pop(2) << endl; 
	cout << "Popped element from stack 1 is " << ks.pop(1) << endl; 
	cout << "Popped element from stack 0 is " << ks.pop(0) << endl; 

	return 0; 
} 
