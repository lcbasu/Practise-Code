#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void Insert(int el, int n)
{
	Node* tmp = new Node();
	tmp->data = el;
	tmp->next = 0;
	if(n==1)
	{
		tmp->next = head;
		head = tmp;
		return;
	}
	Node* t = head;
	for (int i = 0; i < n-2; i++)
	{
		t = t->next;
	}
	tmp->next = t->next;
	t->next = tmp;
}

void Print()
{
	Node* tmp = head;
	while(tmp != 0)
	{
		cout << tmp->data << " ";
		tmp = tmp->next;
	}
	cout << endl;
}

int main()
{
	Node* head = 0;
	Insert(2,1);
	Insert(3,2);
	Insert(4,1);
	Insert(5,2);
	Print();
	return 0;
}