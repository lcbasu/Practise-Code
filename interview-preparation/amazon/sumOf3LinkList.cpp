#include <iostream>
#include <cmath>

using namespace std;

struct LList
{
	int data;
	LList *next;
};

LList *result = NULL;
int carry = 0;

LList *newLList(int data)
{
	LList *tmp = new LList;
	tmp->data = data;
	tmp->next = NULL;

	return tmp;
}

LList *addToFront(LList *head, int data)
{
	if(head == NULL)
	{
		head = newLList(data);
	}
	else
	{
		LList *tmp = newLList(data);
		tmp->next = head;
		head = tmp;
	}
	return head;
}

int length(LList *head)
{
	int count = 0;
	for( ; head != NULL; head = head->next)
	{
		count++;
	}
	return count;
}

void display(LList *head)
{
	for( ; head != NULL; head = head->next)
	{
		cout << head->data << " ";
	}
	cout << endl;
}

void addSame(LList *head1, LList *head2)
{
	if(head1 == NULL)
		return;
	addSame(head1->next, head2->next);
	int sum = head1->data + head2->data + carry;
	result = addToFront(result, sum%10);
	carry = sum/10;
}

void addRemaining(LList *head1, LList *marker)
{
	if(head1 == marker)
		return;
	addRemaining(head1->next, marker);
	int sum = head1->data + carry;
	result = addToFront(result, sum%10);
	carry = sum/10;
}

void sumTwoLList(LList *head1, LList *head2)
{
	if(head1 == NULL || head2 == NULL)
		return;

	int list1Len = length(head1);
	int list2Len = length(head2);
	if(list1Len == list2Len)
	{
		addSame(head1, head2);
	}
	else
	{
		int diff = abs(list1Len-list2Len);

		if(list2Len > list1Len)
		{
			LList *tmp = head1;
			head1 = head2;
			head2 = tmp;
		}

		LList *marker = head1;
		for(int i = 0; i != diff; i++)
		{
			marker = marker->next;
		}
		addSame(marker, head2);
		addRemaining(head1, marker);
	}
	if(carry > 0)
		result = addToFront(result, carry);
}

void sumThreeList(LList *head1, LList *head2, LList *head3)
{
	sumTwoLList(head1, head2);
	LList *tmpResult = result;
	result = NULL;
	sumTwoLList(tmpResult, head3);
}




int main()
{
	LList *num1 = NULL;
	LList *num2 = NULL;
	LList *num3 = NULL;


	num1 = addToFront(num1, 3);
	num1 = addToFront(num1, 2);
	num1 = addToFront(num1, 1);

	num2 = addToFront(num2, 5);
	num2 = addToFront(num2, 4);

	num3 = addToFront(num3, 7);
	num3 = addToFront(num3, 5);
	num3 = addToFront(num3, 9);
	num3 = addToFront(num3, 6);


	display(num1);
	display(num2);
	display(num3);

	sumThreeList(num1, num2, num3);

	display(result);

	return 0;
}
