#include <stdio.h>
#include <malloc.h>
struct node
{
  int data;
  struct node *next;
};
typedef struct node *s;
s head=NULL;

void create(int item)
{
    s temp,New;
    New=(s)malloc(sizeof(struct node));
    New->data=item;
    New->next=NULL;
    if(head==NULL)
        head=New;
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=New;
    }
}
void display()
{
    s temp=head;
    while(temp!=NULL)
    {
        printf("->%d",temp->data);
        temp=temp->next;
    }
}
void duplidel()
{
    s temp1,temp2,t;
    temp1=head;
    while(temp1!=NULL )//&& temp1->next!=NULL)
    {
        temp2=temp1;
        while(temp2->next!=NULL)
        {
            if(temp1->data==temp2->next->data)
            {
                t=temp2->next;
                temp2->next=temp2->next->next;
                free(t);
            }
            else
                temp2=temp2->next;
        }
        temp1=temp1->next;
    }
}
int main()
{
  int n;
  scanf("%d",&n);
  while(n--)
  {
    int a;
    scanf("%d",&a);
    create(a);
  }
  printf("Linked List : ");
  duplidel();
  display();
  return 0;
}
