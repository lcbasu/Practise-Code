#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct LinkedList
{
	int data;
	LinkedList *next;
};


LinkedList *newNode(int el);
LinkedList *addToFront(LinkedList *list, int el);
void displayList(LinkedList *list);
int getListLength(LinkedList *list);

LinkedList *addLists(LinkedList *L1, LinkedList *L2);
void addSameList(LinkedList *L1, LinkedList *L2);
void addRemainingList(LinkedList *L1, LinkedList *tmpL1);
void addToResult(int a, int b);


LinkedList *result = NULL;
int carry = 0;


LinkedList *newNode(int el)
{
	LinkedList *tmp = new LinkedList();
	tmp->data = el;
	tmp->next = NULL;
	return tmp;
}

LinkedList *addToFront(LinkedList *list, int el)
{
	if(list == NULL)
		return newNode(el);
	else
	{
		LinkedList *tmp = newNode(el);
		tmp->next = list;
		return tmp;
	}
}

void displayList(LinkedList *list)
{
	for(LinkedList *tmp = list; tmp != NULL; tmp = tmp->next)
		printf("%d\t", tmp->data);
	printf("\n");
}

int getListLength(LinkedList *list)
{
	int count = 0;
	for(LinkedList *tmp = list; tmp != NULL; tmp = tmp->next)
		count++;
	return count;	
}

LinkedList *addLists(LinkedList *L1, LinkedList *L2)
{
	int len1 = getListLength(L1);
	int len2 = getListLength(L2);
	if(len1 == len2)
		addSameList(L1, L2);
	else
	{
		if(len1 < len2)
		{
			LinkedList *tmp = L1;
			L1 = L2;
			L2 = tmp;
		}
		int diff = abs(len1-len2);
		LinkedList *tmpL1 = L1;
		for (int i = 0; i < diff; ++i)
		{
			tmpL1 = tmpL1->next;
		}
		addSameList(tmpL1, L2);
		addRemainingList(L1, tmpL1);
	}
	if(carry > 0)
		result = addToFront(result, carry);
	return result;
}

void addSameList(LinkedList *L1, LinkedList *L2)
{
	if(L1 == NULL)
		return;
	addSameList(L1->next, L2->next);
	addToResult(L1->data, L2->data);
}

void addRemainingList(LinkedList *L1, LinkedList *tmpL1)
{
	if (L1 == tmpL1)
		return;
	int sum = L1->data + carry;
	int digit = sum % 10;
	carry = sum / 10;
	result = addToFront(result, digit);
}


void addToResult(int a, int b)
{
	int sum = a + b  +carry;
	int digit = sum % 10;
	carry = sum / 10;
	result = addToFront(result, digit);
}


int main()
{
	LinkedList *L1, *L2;
	L1 = NULL;
	L2 = NULL;
	L1 = addToFront(L1, 9);
	L1 = addToFront(L1, 9);
	L1 = addToFront(L1, 9);
	L1 = addToFront(L1, 9);
	L1 = addToFront(L1, 9);


	L2 = addToFront(L2, 9);
	L2 = addToFront(L2, 9);
	L2 = addToFront(L2, 9);

	printf("List 1 :\t");
	displayList(L1);
	printf("\n");
	printf("List 2 :\t");
	displayList(L2);

	LinkedList *finalResult = addLists(L1, L2);
	printf("\nResult :\t");
	displayList(finalResult);	

	return 0;
}