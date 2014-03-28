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


void deleteFromMid(Node *midPtr)
{
	if(midPtr == NULL || midPtr->next == NULL)	//null case and the last node case
		return;
	Node *prev = midPtr;
	Node *succ = midPtr->next;
	while(succ->next != NULL)
	{
		prev->data = succ->data;
		prev = prev->next;
		succ = succ->next;
	}
	prev->data = succ->data;
	prev->next = NULL;
	delete succ;
}

int main()
{
	Node *head = NULL;
	Node *midPtr;
	head = addNode(head, 5);
	head = addNode(head, 4);
	head = addNode(head, 3);
	head = addNode(head, 2);
	head = addNode(head, 1);

	cout << "Before : " << endl;
	display(head);

	midPtr = head;
	for (int i = 0; i < 2; ++i)
	{
		midPtr = midPtr->next;
	}

	cout << "Mid Data :\t" << midPtr->data << endl;

	deleteFromMid(midPtr);

	cout << "After : " << endl;
	display(head);

	return 0;
}