#include <iostream>

using namespace std;

struct Node
{
	int data;
	Node* next;
};

Node* head;

void split(Node* head, Node** firstList, Node** secondList)
{
	Node* slow;
	Node* fast;
	if(head == NULL || head->next == NULL)
	{
		*firstList = head;
		*secondList = NULL;
	}
	else
	{
		slow = head;
		fast = head->next;
		while(fast != NULL)
		{
			fast = fast->next;
			if(fast != NULL)
			{
				slow = slow->next;
				fast = fast->next;
			}
		}

		*firstList = head;
		*secondList = slow->next;
		slow->next = NULL;
	}
}

Node* merge(Node* firstList, Node* secondList)
{
	Node* final = NULL;
	if(firstList == NULL)
		return secondList;
	else if(secondList == NULL)
		return firstList;
	if(firstList->data <= secondList->data)
	{
		final = firstList;
		final->next = merge(firstList->next, secondList);
	}
	else
	{
		final = secondList;
		final->next = merge(firstList, secondList->next);
	}
	return final;
}


Node* SortList(Node *head)
{
	Node *firstList, *secondList;
	if(head == NULL || head->next == NULL)
		return head;
	split(head, &firstList, &secondList);
	firstList = SortList(firstList);
	secondList = SortList(secondList);
	head = merge(firstList, secondList);
	return head;
}

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
	head = SortList(head);
	print();
	return 0;
}