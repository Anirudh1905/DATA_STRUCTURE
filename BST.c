#include <stdio.h>
#include <stdlib.h>
int c=0;
struct node
{
    int data;
    struct node *right;
    struct node *left;
}*root=NULL;
struct node *newnode(int item)
{
    struct node *temp=(struct node *)malloc(sizeof(struct node));
    temp->data=item;
    temp->left=temp->right=NULL;
    return temp;
}
struct node* insert(struct node* root,int key)
{
    if (root==NULL)
         return newnode(key);
    if (key<root->data)
        root->left=insert(root->left,key);
    else
        root->right=insert(root->right,key);
    return root;
}
void preorder(struct node* root)
{
    if(root!=NULL)
    {
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}
void inorder(struct node* root)
{
    if(root!=NULL)
    {
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}
void postorder(struct node* root)
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}
struct node* findlargest(struct node* root)
{
    struct node* cur=root;
    while(cur && cur->right!=NULL)
        cur=cur->right;
    return cur;
}
struct node* findsmallest(struct node* root)
{
    struct node* current = root;
    while (current && current->left != NULL)
        current = current->left;
    return current;
}
int height(struct node *root)
{
    int h;
    if(root==NULL)
        return 0;
    else
    {
        int l=height(root->left);
        int r=height(root->right);
        if(l>r)
        {
            return(l+1);
        }
        else
        {
            return(r+1);
        }
    }
}
void printLevel(struct node* root, int level)
{
    if(root == NULL)
        return;
    if(level == 1)
        printf("%d ", root->data);
    else if (level > 1)
    {
        printLevel(root->left, level-1);
        printLevel(root->right, level-1);
    }
}
void levelorder(struct node* root)
{
    int h = height(root);
    int i;
    for(i=1;i<=h;i++)
    {
        printLevel(root,i);
        printf("\n");
    }
}
int countLeafNode(struct node *root)
{
    if(root)
    {
        if(root->left == NULL && root->right == NULL)
            c++;
        if(root->left)
            {countLeafNode(root->left);}
        if(root->right)
            {countLeafNode(root->right);}
    }
    return c;
}
int search(struct node* root, int key)
{
    if(root)
    {
        if (root->data==key)
            return 1;
        else
        {
            if (root->data<key)
                return search(root->right, key);
            else
                return search(root->left, key);
        }
    }
    return 0;
}
struct node* deletenode(struct node* root,int key)
{
    if(root==NULL)
        return root;
    if(key<root->data)
        root->left=deletenode(root->left,key);
    else if(key>root->data)
        root->right=deletenode(root->right,key);
    else
    {
        if(root->left==NULL && root->right==NULL)//deleting child
        {
            free(root);
            root=NULL;
        }
        else if(root->left==NULL)//deleting node having only right child
        {
            struct node *temp;
            temp=root;
            root=root->right;
            free(temp);
        }
        else if(root->right==NULL)//deleting node having only left child
        {
            struct node *temp1;
            temp1=root;
            root=root->left;
            free(temp1);
        }
        else//deleting node having 2 child
        {
            struct node *temp2=findsmallest(root->right);
            root->data=temp2->data;
            root->right=deletenode(root->right,temp2->data);
        }
    }
    return root;
}
int main()
{
   int n,x,y;
   scanf("%d %d",&n,&y);
   while(n--)
   {
       scanf("%d",&x);
       root=insert(root,x);
   }
   printf("\nLargest element is : %d",findlargest(root)->data);
   printf("\nSmallest element is : %d",findsmallest(root)->data);
   printf("\nHeight is: %d",height(root));
   printf("\nLEAF NODES: %d",countLeafNode(root));
   printf("\nPREORDER\n");
   preorder(root);
   printf("\nINORDER\n");
   inorder(root);
   printf("\nPOSTORDER\n");
   postorder(root);
   printf("\nLEVELORDER\n");
   levelorder(root);
   if(search(root,y)==1)
   {
       printf("Element is present\n");
       root=deletenode(root,y);
       printf("LEVELORDER\n");
       levelorder(root);
       printf("Element %d is deleted",y);
   }
   else
       printf("Element is not present\n");
   return 0;
}
