#include <stdio.h>
#include <malloc.h>
#include <string.h>
typedef struct node s;
struct node
{
  char data;
  struct node *next;
}*head=NULL;
void create(char ch)
{
  s *newnode=(s*)malloc(sizeof(s));
  s *temp;
  newnode->data=ch;
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
s*rev()
{
    struct node *cur,*pre,*net;
    pre=NULL;
    cur=head;
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

int main()
{
  char str[100];
  scanf("%s",str);
  int l=strlen(str),i,flag;
  for(i=0;i<l;i++)
    create(str[i]);
  s *temp=head;
  s *temp2=rev(head);
  while(temp!=NULL)
  {
    if(temp->data!=temp2->data)
    {
        flag=-1;
    }
    temp2=temp2->next;
    temp=temp->next;
  }
  if(flag==-1)
    printf("\nNot Palindrome");
  else
    printf("\nIs Palindrome");
  return 0;
}
