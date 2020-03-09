#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
}*head;
void create(int x)
{
    struct node *temp,*newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=x;
    newnode->next=NULL;
    if(head==NULL)
        head=newnode;
    else
    {
        temp=head;
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=newnode;
    }
}
void del(int k)
{
    struct node *temp1=head,*temp2;
    while(temp1)
    {
        while(temp1->data!=k)
        {
            temp2=temp1;
            temp1=temp1->next;
        }
        if(temp1==NULL) cout<<"bbjh";
        temp2->next=temp1->next;
        free(temp1);
        temp1=temp2->next;
    }
}
void display(struct node* head)
{
    struct node *temp;temp=head;
    while(temp!=NULL)
    {
        printf("%d-> ",temp->data);
        temp=temp->next;
    }
}
int main()
{
    int n,a,k;
    scanf("%d %d",&n,&k);
    while(n--)
    {
        scanf("%d",&a);
        create(a);
    }

   del(k);
    display(head);
    return 0;
}
