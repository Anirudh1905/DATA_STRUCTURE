#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data,i;
    struct node *next;
}*head;
int main()
{
    int n,x,y,z;
    scanf("%d",&n);
    createlist(n);
    printf("enter the no. and value\n");
    scanf("%d %d",&y,&z);
    x=search(head,y);
    if(x==0)
        insertbefore(y,z);
    else
        printf("h1");
    displaylist();
    return 0;
}
void createlist(int n)
{
    struct node *newNode,*temp;
    int data,i;
    head=(struct node*)malloc(sizeof(struct node));
    if(head==NULL)
    {
        printf("Unable to allocate memory");
    }
    else
    {
        printf("enter data of node 1:");
        scanf("%d",&data);
        head->data=data;
        head->next=NULL;
        temp=head;
        for(i=2;i<=n;i++)
        {
            newNode=(struct node*)malloc(sizeof(struct node));
            if(newNode==NULL)
            {
                printf("unable to allocate memory");
                break;
            }
            else
            {
                printf("enter the data of %d: ",i);
                scanf("%d",&data);
                newNode->data=data;
                newNode->next=NULL;
                temp->next=newNode;
                temp=temp->next;
            }
        }
    }
}
void displaylist()
{
    struct node *temp;
    if(head==NULL)
    {
        printf("list is empty");
    }
    else
    {
        temp=head;
        printf("Linked List created\n");
        while(temp!=NULL)
        {
            printf("->%d",temp->data);
            temp=temp->next;
        }
    }
}
void insertbefore(int num,int value)
{
    struct node *temp1,*newNode;
    temp1=head;
    newNode=(struct node*)malloc(sizeof(struct node));
    newNode->data=value;
    while(temp1->data!=num && temp1!=NULL)
    {
        temp1=temp1->next;
    }
    newNode->next=temp->next;
    temp1->next=newNode;
}
int search(struct node *head, int key)
{
    while (head != NULL)
    {
        if (head->data == key)
        {
            return 0;
        }
        head = head->next;
    }
    printf("Node not found! \n");
    return 1;
}
