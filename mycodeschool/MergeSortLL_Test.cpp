#include <iostream>

using namespace std;

struct Node
{
	int data; 
	Node* next;
};

void split(Node* head, Node** firstList, Node** secondList)
{
	if(head == NULL || head->next == NULL)
	{
		*firstList = head;
		*secondList = NULL;
		return;
	}
	Node* slow = head;
	Node* fast = head->next;
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

Node* merge(Node* firstList, Node* secondList)
{
	Node* result = NULL;
	if(firstList == NULL)
		return secondList;
	else if(secondList == NULL)
		return firstList;
	if(firstList->data <= secondList->data)
	{
		result = firstList;
		result->next = merge(firstList->next, secondList);
	}
	else
	{
		result = secondList;
		result->next = merge(firstList, secondList->next);
	}
	return result;
}

Node* mergeSort(Node* head)
{
	if(head == NULL || head->next == NULL)
		return head;
	Node *firstList, *secondList;
	split(head, &firstList, &secondList);
	firstList = mergeSort(firstList);
	secondList = mergeSort(secondList);
	head = merge(firstList, secondList);
	return head;
}