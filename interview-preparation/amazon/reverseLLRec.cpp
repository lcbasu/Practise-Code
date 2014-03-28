#include <iostream>
#include <algorithm>

using namespace std;

struct Node
{
	int data;
	Node *next;
};

Node *newNode(int data)
{
	Node *tmp = new Node;
	tmp->data = data;
	tmp->next = NULL;
	return tmp;
}

Node *addToHead(Node *head, int data)
{
	Node *tmp = newNode(data);
	if(head == NULL)
	{
		head = tmp;
	}
	else
	{
		tmp->next = head;
		head = tmp;
	}
	return head;
}

void display(Node *head)
{
	for( ; head != NULL; head = head->next)
	{
		cout << head->data << " ";
	}
	cout << endl;
}

void reverseRec(Node **head)
{
	if(*head == NULL)
		return;
	Node *first;
	Node *rest;
	first = *head;

	if(first == NULL)
		return;

	rest = first->next;

	if(rest == NULL)
		return;

	reverseRec(&rest);
	first->next->next = first;
	first->next = NULL;

	*head = rest;

}

int main()
{
	Node *head = NULL;

	head = addToHead(head, 20);
	head = addToHead(head, 4);
	head = addToHead(head, 15);
	head = addToHead(head, 85);
	head = addToHead(head, 50);
	head = addToHead(head, 17);

	display(head);

	reverseRec(&head);

	display(head);

	return 0;
}
