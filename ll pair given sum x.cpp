// C++ program to find a pair with given sum x. 
#include<bits/stdc++.h> 
using namespace std; 

// structure of node of doubly linked list 
struct Node 
{ 
	int data; 
	struct Node *next, *prev; 
}; 
void pairSum(struct Node *head, int x) 
{ 
	struct Node *a=head,*b=head;
	while(b->next)
	    b=b->next;
	while(a && b && a!=b && b->next!=a)
	{
	    if(a->data+b->data==x)
	    {
	        cout<<a->data<<" "<<b->data<<endl;
	        a=a->next;
	        b=b->prev;
	    }
	    else if(a->data+b->data>x)
	    {
	        b=b->prev;
	    }
	    else
	        a=a->next;
	}
} 

void insert(struct Node **head, int data) 
{ 
	struct Node *temp = new Node; 
	temp->data = data; 
	temp->next = temp->prev = NULL; 
	if (!(*head)) 
		(*head) = temp; 
	else
	{ 
		temp->next = *head; 
		(*head)->prev = temp; 
		(*head) = temp; 
	} 
} 

// Driver program 
int main() 
{ 
	struct Node *head = NULL; 
	insert(&head, 9); 
	insert(&head, 8); 
	insert(&head, 6); 
	insert(&head, 5); 
	insert(&head, 4); 
	insert(&head, 2); 
	insert(&head, 1); 
	int x = 7; 
	pairSum(head, x); 

	return 0; 
} 
