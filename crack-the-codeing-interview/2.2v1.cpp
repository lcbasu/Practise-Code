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


int findKth(Node *nodePtr, int k)
{
	if(nodePtr == NULL)
		return 0;
	int count = findKth(nodePtr->next, k) + 1;
	if(count == k)
		cout << "Kth Node data :\t" << nodePtr->data << endl;
	return count;
}


int main()
{
	Node *head = NULL;
	head = addNode(head, 5);
	head = addNode(head, 4);
	head = addNode(head, 3);
	head = addNode(head, 2);
	head = addNode(head, 1);
	display(head);
	int k = 5;

	int count = findKth(head, k);

	return 0;
}