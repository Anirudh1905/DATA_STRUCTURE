// C++ program to rotate a Doubly linked 
// list counter clock wise by N times 
#include <bits/stdc++.h> 
using namespace std; 

/* Link list node */
struct Node { 
	char data; 
	struct Node* prev; 
	struct Node* next; 
}; 

void rotate(struct Node** head_ref, int N) 
{
    if(N==0)
        return;
	int c=1;struct Node *cur=(*head_ref),*t1=(*head_ref);
	while(c<N && cur)
	{
	    cur=cur->next;
	    c++;
	}
	if(!cur)
	    return;
	while(t1->next)
	    t1=t1->next;
	t1->next=(*head_ref);
	(*head_ref)->prev=t1;
	(*head_ref)=cur->next;
	(*head_ref)->prev=NULL;
	cur->next=NULL;
} 

// Function to insert a node at the 
// beginning of the Doubly Linked List 
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = new Node; 
	new_node->data = new_data; 
	new_node->prev = NULL; 
	new_node->next = (*head_ref); 
	if ((*head_ref) != NULL) 
		(*head_ref)->prev = new_node; 
*head_ref = new_node; 
} 

/* Function to print linked list */
void printList(struct Node* node) 
{ 
	while (node->next != NULL) { 
		cout << node->data << " "
			<< "<=>"
			<< " "; 
		node = node->next; 
	} 
	cout << node->data; 
} 

// Driver's Code 
int main(void) 
{ 
	/* Start with the empty list */
	struct Node* head = NULL; 

	/* Let us create the doubly 
	linked list a<->b<->c<->d<->e */
	push(&head, 'e'); 
	push(&head, 'd'); 
	push(&head, 'c'); 
	push(&head, 'b'); 
	push(&head, 'a'); 

	int N = 2; 

	cout << "Given linked list \n"; 
	printList(head); 
	rotate(&head, N); 

	cout << "\nRotated Linked list \n"; 
	printList(head); 

	return 0; 
} 
