#include <iostream>

using namespace std;


struct Node
{
	int data;
	Node *next;
};

void display(Node *head)
{
	if(head == NULL)
		return;
	Node *tmp;
	for(tmp = head; tmp != NULL; tmp = tmp->next)
	{
		cout << tmp->data << " ";
	}
	cout << endl;
}


Node *addNode(Node *head, int el)
{
	Node *newNode = new Node();
	newNode->data = el;
	newNode->next = NULL;
	if(head != NULL)
	{
		newNode->next = head;
	}
	head = newNode;
	return head;
}


Node *partition(Node *head, int x)
{
	if(head == NULL || head->next == NULL)
		return head;
	Node *prev = head;
	Node *succ = head->next;

	while(succ != NULL)
	{
		if(succ->data < x)
		{
			prev->next = succ->next;
			succ->next = head;
			head = succ;
			succ = prev->next;
		}
		else
		{
			prev = prev->next;
			succ = succ->next;
		}
	}
	return head;
}


int main()
{
	Node *head = NULL;
	head = addNode(head, 4);
	head = addNode(head, 2);
	head = addNode(head, 1);
	head = addNode(head, 11);
	head = addNode(head, 3);
	head = addNode(head, 7);

	cout << "Before : " << endl;
	display(head);

	int x = 4;

	head = partition(head, x);

	cout << "After : " << endl;
	display(head);

	return 0;
}