#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
	Node* prev;
};

Node* head;

void Print(Node* head)
{
	if(head == 0)
		return;
	else
	{
		Node* tmp = head;
		while(tmp != 0)
		{
			cout << tmp->data << " ";
			tmp = tmp->next;
		}
		cout << endl;
	}
}

Node* SortedInsert(Node *head,int data)
{
	Node* tmp = new Node();
	tmp->data = data;

	if(head == NULL)
	{
		tmp->next = NULL;
		tmp->prev = NULL;
		head = tmp;
		return head;
	}
	Node* current = head;
	while(current->next != NULL && current->data <= data)
	{
		current = current->next;
	}
	cout << "Current : " << current->data << endl;
	if(current == head && current->data > data)
	{
		tmp->next = head;
		tmp->prev = NULL;
		head->prev = tmp;
		head = tmp;
	}
	else if(current->next == NULL && current->data <= data)
	{
		tmp->next = NULL;
		current->next = tmp;
		tmp->prev = current;
	}
	else
	{
		tmp->next = current;
		tmp->prev = current->prev;
		current->prev->next = tmp;
	}
	return head;
}

int main()
{
	head = NULL;
	head = SortedInsert(head, 2);
	Print(head);
	head = SortedInsert(head, 2);
	Print(head);
	head = SortedInsert(head, 2);
	Print(head);
	head = SortedInsert(head, 4);
	Print(head);	
	head = SortedInsert(head, 3);
	Print(head);
	head = SortedInsert(head, 5);
	Print(head);
	return 0;
}