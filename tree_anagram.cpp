/* Iterative program to check if two trees are level
by level anagram. */
#include <bits/stdc++.h>
using namespace std;

// A Binary Tree Node
struct Node
{
	struct Node *left, *right;
	int data;
};

// Returns true if trees with root1 and root2
// are level by level anagram, else returns false.
bool areAnagrams(Node *root1, Node *root2)
{
	if(!root1 && !root2)
	    return true;
	if(!root1 || !root2)
	    return false;
	queue<Node*>q1,q2;
	q1.push(root1);q2.push(root2);
	while(!q1.empty() || !q2.empty())
	{
	    int n1=q1.size(),n2=q2.size();
	    if(n1!=n2)
	        return false;
	    if(n1==0)
	        break;
	    int s1=0,m1=1,s2=0,m2=1;
	    while(n1>0)
	    {
	        Node *tmp1=q1.front();
	        q1.pop();
	        if(tmp1->left)
	            q1.push(tmp1->left);
	        if(tmp1->right)
	            q1.push(tmp1->right);
	        n1--;
	        Node *tmp2=q2.front();
	        q2.pop();
	        if(tmp2->left)
	            q2.push(tmp2->left);
	        if(tmp2->right)
	            q2.push(tmp2->right);
	        s1+=tmp1->data;m1*=tmp1->data;
	        s2+=tmp2->data;m2*=tmp2->data;
	    }
	    
	    if(s1!=s2 && m1!=m2)
	        return false;
	}
	return true;
}

// Utility function to create a new tree Node
Node* newNode(int data)
{
	Node *temp = new Node;
	temp->data = data;
	temp->left = temp->right = NULL;
	return temp;
}

// Driver program to test above functions
int main()
{
	struct Node* root1 = newNode(1);
    root1->left = newNode(3);
    root1->right = newNode(2);
    root1->right->left = newNode(5);
    root1->right->right = newNode(4);
  
    struct Node* root2 = newNode(1);
    root2->left = newNode(2);
    root2->right = newNode(3);
    root2->left->left = newNode(4);
    root2->left->right = newNode(5);
	areAnagrams(root1, root2)? cout << "Yes" : cout << "No";
	return 0;
}
