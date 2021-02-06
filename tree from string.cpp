/* C++ program to construct a binary tree from the given string */
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	Node *left, *right;
};

Node* newNode(int data)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->data = data;
	node->left = node->right = NULL;
	return (node);
}

void preOrder(Node* node)
{
	if (node == NULL)
		return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}

int findIndex(string str, int si, int ei)
{
    if(si>ei)
        return -1;
    stack<char>stk;
    for(int i=si;i<=ei;i++)
    {
        if(str[i]=='(')
            stk.push(str[i]);
        else if(str[i]==')')
        {
            if(stk.top()=='(')
                stk.pop();
            if(stk.empty())
                return i;
        }
    }
    return -1;
}

Node* treeFromString(string str, int si, int ei)
{
    if(si>ei)
        return NULL;
    Node* root=newNode(str[si]-'0');
    int indx=-1;
    if(si+1<=ei && str[si+1]=='(')
        indx=findIndex(str,si+1,ei);
    if(indx!=-1)
    {
        root->left=treeFromString(str,si+2,indx-1);
        root->right=treeFromString(str,indx+2,ei-1);
    }
    return root;
}

// Driver Code
int main()
{
	string str = "4(2(3)(1))(6(5))";
	Node* root = treeFromString(str, 0, str.length() - 1);
	preOrder(root);
}
