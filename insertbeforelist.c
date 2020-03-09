#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data,i;
    struct node *next;
}*head=NULL;
void create();
int search(int);
void insertbefore(int,int);
void display();
int main()
{
    int x,y,z;
    create();
    printf("enter the no. and value\n");
    scanf("%d %d",&y,&z);
    x=search(y);
    if(x==0)
        insertbefore(y,z);
    else
        printf("Node not found! \n");
    display();
    return 0;
}
void create()
{
    struct node *newNode,*temp;
    int data,i,n;
    scanf("%d",&n);
    head=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&data);
    head->data=data;
    head->next=NULL;
    temp=head;
    for(i=2;i<=n;i++)
    {
        newNode=(struct node*)malloc(sizeof(struct node));
        scanf("%d",&data);
        newNode->data=data;
        newNode->next=NULL;
        temp->next=newNode;
        temp=temp->next;
    }
}
void display()
{
    struct node *temp;
    temp=head;
    printf("Linked List created\n");
    while(temp!=NULL)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
}
void insertbefore(int num,int value)
{
    struct node *temp1,*temp2,*newNode;
    temp1=head;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    while(temp1->data!=num && temp1!=NULL)
    {
        temp2=temp1;
        temp1=temp1->next;
    }
    newNode->next=temp2->next;
    temp2->next=newNode;
}
int search(int key)
{
    struct node *temp=head;
    while (temp!=NULL)
    {
        if (temp->data==key)
        {
            return 0;
        }
        temp=temp->next;
    }
    return 1;
}
