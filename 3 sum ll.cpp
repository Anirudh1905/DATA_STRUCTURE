// C++ implementation to count triplets in a sorted doubly linked list
// whose sum is equal to a given value 'x'
#include <bits/stdc++.h>
using namespace std;
struct Node {
	int data;
	struct Node* next, *prev;
};

int countPairs(struct Node* first, struct Node* last, int value)
{
    int c=0;
	while(first && last && first!=last && last->next!=first)
	{
	    if(first->data+last->data==value)
	    {
	        c++;
	        first=first->next;
	        last=last->prev;
	    }
	    else if(first->data+last->data>value)
	        last=last->prev;
	    else
	        first=first->next;
	}
	return c;
}

int countTriplets(struct Node* head, int x)
{
	 Node *first=head,*last=head,*cur=head;int c=0;
	 if(!head)
	    return 0;
	 while(last->next)
	    last=last->next;
	 while(cur)
	 {
	     first=cur->next;
	     c+=countPairs(first,last,x-cur->data);
	     cur=cur->next;
	 }
	 return c;
}

void insert(struct Node** head, int data)
{
	struct Node* temp = new Node();
	temp->data = data;
	temp->next = temp->prev = NULL;

	if ((*head) == NULL)
		(*head) = temp;
	else {
		temp->next = *head;
		(*head)->prev = temp;
		(*head) = temp;
	}
}

// Driver program to test above
int main()
{
	struct Node* head = NULL;
	insert(&head, 9);
	insert(&head, 8);
	insert(&head, 6);
	insert(&head, 5);
	insert(&head, 4);
	insert(&head, 2);
	insert(&head, 1);
	int x = 17;
	cout << "Count = "
		<< countTriplets(head, x);
	return 0;
}
