// C++ program to replace every element with the
// least greater element on its right
#include <bits/stdc++.h>
using namespace std;

// A binary Tree node
struct Node
{
	int data;
	Node *left, *right;
};

// A utility function to create a new BST node
Node* newNode(int item)
{
	Node* temp = new Node;
	temp->data = item;
	temp->left = temp->right = NULL;

	return temp;
}

/* A utility function to insert a new node with
given data in BST and find its successor */
void insert(Node*& root, int data, Node*& suc)
{
	if(!root)
	    root=newNode(data);
	if(root->data>data)
	{
	    suc=root;
	    insert(root->left,data,suc);
	}
	else if(root->data<data)
	    insert(root->right,data,suc);
}

// Function to replace every element with the
// least greater element on its right
void replace(int a[], int n)
{
    Node* root=NULL;
	for(int i=n-1;i>=0;i--)
	{
	    Node* suc=NULL;
	    insert(root,a[i],suc);
	    if(suc)
	        a[i]=suc->data;
	    else
	        a[i]=-1;
	}
}

// Driver Program to test above functions
int main()
{
	int arr[] = { 8, 58, 71, 18, 31, 32, 63, 92,
				43, 3, 91, 93, 25, 80, 28 };
	int n = sizeof(arr)/ sizeof(arr[0]);

	replace(arr, n);

	for (int i = 0; i < n; i++)
		cout << arr[i] << " ";

	return 0;
}
