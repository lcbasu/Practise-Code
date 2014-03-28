#include <iostream>

using namespace std;

struct Node
{
	Node *next;
	int data;
};

int cost(Node *X, Node *Y)
{
	if(X->next == Y)
		return 1;
	else if(X==Y)
		return 0;
	else
		return -1;
}

int main()
{
	Node *head = new Node();
	head->data = 10;
	head->next = NULL;
	Node *B = new Node;
	B->data = 20;
	B->next = NULL;

	//linking head->B

	head->next = B;

	Node *C = new Node;
	C->data = 30;
	C->next = NULL;
	cout << cost(head, B) << endl;

	return 0;
}