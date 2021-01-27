#include <bits/stdc++.h>
using namespace std;
class Node {
public:
	int data;
	Node* next;
};
void push(Node** head_ref, int data)
{
    Node* p=new Node();
    p->data=data;
    p->next=*head_ref;
    if(*head_ref)
    {
        Node *temp=*head_ref;
        while(temp->next!=*head_ref)
            temp=temp->next;
        temp->next=p;
    }
    else
        p->next=p;
    *head_ref=p;
}
void deleteNode(Node** head, int key) 
{
	if(!*head) //empty list
	    return;
	if((*head)->data==key && (*head)->next==*head) //single node
	{
	    free(*head);
	    *head=NULL;
	    return;
	}
	Node *tmp=*head,*d;
	if((*head)->data==key) //deleting head
	{
	    while(tmp->next!=*head)
	        tmp=tmp->next;
	    tmp->next=(*head)->next;
	    free(*head);
	    *head=tmp->next;
	}
    while(tmp->next!=*head && tmp->next->data!=key) //nth elemnt in list
	{
	    tmp=tmp->next;
	}
	if(tmp->next->data==key)
	{
	    d=tmp->next;
	    tmp->next=d->next;
	    free(d);
	}
	else
	    cout<<"Not found";

}
void printList(Node* head)
{
	Node* temp = head;
	if (head != NULL) {
		do {
			cout << temp->data << " ";
			temp = temp->next;
		} while (temp != head);
	}
	cout << endl;
}
int main()
{
	Node* head = NULL;
	push(&head, 2);
	push(&head, 5);
	push(&head, 7);
	push(&head, 8);
	push(&head, 10);
	cout << "List Before Deletion: ";
	printList(head);
	deleteNode(&head, 7);
	cout << "List After Deletion: ";
	printList(head);
	return 0;
}
