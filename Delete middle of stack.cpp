// C++ code to delete middle of a stack 
// without using additional data structure. 
#include<bits/stdc++.h> 
using namespace std; 

// Deletes middle of stack of size 
// n. Curr is current item number 
void deleteMid(stack<char> &st, int c,int k) 
{ 
    if(st.empty())
        return;
    char x=st.top();
    st.pop();
    if(c==k)
    {
        return;
    }
    deleteMid(st,c+1,k);
    st.push(x);
} 

//Driver function to test above functions 
int main() 
{ 
	stack<char> st; 
	//push elements into the stack 
	st.push('1'); 
	st.push('2'); 
	st.push('3'); 
	st.push('4'); 
	st.push('5'); 
	st.push('6'); 
	st.push('7'); 
    int k=(st.size()/2)+1;
	deleteMid(st,1,k); 

	// Printing stack after deletion 
	// of middle. 
	while (!st.empty()) 
	{ 
		char p=st.top(); 
		st.pop(); 
		cout << p << " "; 
	} 
	return 0; 
} 
