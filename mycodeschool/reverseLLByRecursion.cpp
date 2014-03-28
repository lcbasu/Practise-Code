#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void insertAtBeg(int el)
{
	Node* tmp = new Node();
	tmp->data = el;
	tmp->next = head;
	head = tmp;
}

void print()
{
	Node* tmp = head;
	while(tmp != 0)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

void reverse(Node* p)
{
	if(p->next == 0)
	{
		head = p;
		return;
	}
	reverse(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = 0;
}

Node* ReverseDLL(Node* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	Node* current = head;
	Node* tmp1 = NULL;
	Node* tmp2 = NULL;
	while(current->next != NULL)
	{
		tmp1 = current->prev;
		tmp2 = current->next;
		current->prev = current->next;
		current->next = tmp1;
		current = tmp2;
	}
	current->next = current->prev;
	current->prev = NULL;
	head = current;

	return head;
}

int main()
{
	head = 0;
	insertAtBeg(1);
	insertAtBeg(2);
	insertAtBeg(3);
	insertAtBeg(4);
	insertAtBeg(5);
	insertAtBeg(6);
	print();
	reverse(head);
	print();
	return 0;
}