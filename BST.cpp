#include <iostream>
using namespace std;

class Treenode{
    public:
    int data;
    Treenode *left,*right;
    Treenode(int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
Treenode* buildTree(Treenode *root,int x)
{
    if(!root)
    {
        Treenode* tmp=new Treenode(x);
        return tmp;
    }
    if(root->data<x)
        root->right=buildTree(root->right,x);
    else if(root->data>x)
        root->left=buildTree(root->left,x);
    return root;
}
void inorder(Treenode* root)
{
    if(!root)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
int main()
{
    int a[]={2,3,1,4,5,0,6,7,8,9};Treenode* root=NULL;
    for(int i=0;i<10;i++)
    {
        root=buildTree(root,a[i]);
    }
    inorder(root);
    return 0;
}
