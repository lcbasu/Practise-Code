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

Node *reverse(Node *head)
{
	Node *prev = NULL;
	Node *curr = head;
	Node *succ;
	while(curr != NULL)
	{
		succ = curr->next;
		curr->next = prev;
		prev = curr;
		head = curr;
		curr = succ;
	}
	return head;
}

int main()
{
	Node *head = NULL;

	head = addToHead(head, 20);
	head = addToHead(head, 4);
	head = addToHead(head, 15);
	head = addToHead(head, 85);

	display(head);

	head = reverse(head);

	display(head);

	return 0;
}
