#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
}*head=NULL;
void create(int x)
{
    struct node *newnode,*temp;
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
int count(int y)
{
    struct node *temp=head;int c=0;
    while(temp!=NULL)
    {
        if(temp->data==y)
        {
            c++;
        }
        temp=temp->next;
    }
    return c;
}
void swap(int *a,int *b)
{
    int t=0;
    t=*a;
    *a=*b;
    *b=t;
}
void swappairwise(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        swap(&temp->data,&temp->next->data);
        temp=temp->next->next;
    }
}
struct node* rev(struct node *head)
{
    struct node *cur,*pre,*net;
    cur=head;
    pre=NULL;
    while(cur!=NULL)
    {
        net=cur->next;
        cur->next=pre;
        pre=cur;
        cur=net;
    }
    head=pre;
    return head;
}
struct node *del(struct node *head,int x)
{
    struct node *temp1=head,*temp2=head;
    while(temp1!=NULL)
    {
        if(temp1->data==x && temp1==head)
        {
            head=temp1->next;
            temp1=head;
            temp2=temp1;
        }
        else if(temp1->data==x && temp1!=head)
        {
            temp2->next=temp1->next;
             free(temp1);
            temp1=temp2->next;
        }
        else
        {
            temp2=temp1;
            temp1=temp1->next;
        }
    }
    return head;
}
void disp(struct node *head)
{
    struct node *temp=head;
    while(temp!=NULL)
    {
        printf("%d ",temp->data);
        temp=temp->next;
    }
    printf("\n");
}
int main()
{
    int n,w,a;
    scanf("%d %d",&n,&w);
    while(n--)
    {
        scanf("%d",&a);
        create(a);
    }
    disp(head);
    //printf("%d ",count(w));
    //disp(rev(head));
    //swappairwise(head);
    disp(del(head,w));

    return 0;
}
