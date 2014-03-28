#include <iostream>
#include <algorithm>
#include <cmath>

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

int length(Node *head)
{
	int count = 0;
	while(head != NULL)
	{
		count++;
		head = head->next;
	}
	return count;
}

Node *getIntersectionNode(Node *head1, Node *head2)
{
	int len1 = length(head1);
	int len2 = length(head2);

	int diff = abs(len1-len2);

	if(len2 > len1)
	{
		Node *tmp = head1;
		head1 = head2;
		head2 = tmp;
	}

	while(diff--)
	{
		head1 = head1->next;
	}
	while(head1 != head2)
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	return head1;
}

int main()
{
	Node *head = NULL;
	Node *head2;

	head = addToHead(head, 20);
	head = addToHead(head, 4);
	head = addToHead(head, 15);
	head = addToHead(head, 85);
	head2 = head;
	head = addToHead(head, 50);
	head = addToHead(head, 17);

	display(head);


	head2 = addToHead(head2, 29);
	head2 = addToHead(head2, 27);
	head2 = addToHead(head2, 25);

	display(head2);

	Node *mergerPoint = getIntersectionNode(head, head2);

	cout << mergerPoint->data << endl;

	return 0;
}
