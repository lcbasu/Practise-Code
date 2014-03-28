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


Node *addNode(Node *head, int data)
{
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	if(head == NULL)
	{
		head = newNode;
	}
	else
	{
		Node *tmp;
		for(tmp = head; tmp->next != NULL; tmp = tmp->next);
		tmp->next = newNode;
	}
	return head;
}

int length(Node *list)
{
	int count = 0;
	for( ; list != NULL; list = list->next)
	{
		count++;
	}
	return count;
}

Node *sumOfNodes(Node *list1, Node *list2)
{
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;
	int carry = 0;
	int sum;

	Node *result = NULL;

	int list1Len = length(list1);
	int list2Len = length(list2);

	if(list2Len > list1Len)
	{
		Node *tmp = list1;
		list1 = list2;
		list2 = tmp;
	}

	while(list1 != NULL && list2 != NULL)
	{
		sum = list1->data + list2->data + carry;
		result = addNode(result, sum%10);
		carry = sum/10;
		list1 = list1->next;
		list2 = list2->next;
	}
	while(list1 != NULL)
	{
		sum = list1->data + carry;
		result = addNode(result, sum%10);
		carry = sum/10;
		list1 = list1->next;
	}
	if(carry > 0)
		result = addNode(result, carry);
	return result;
}

int main()
{
	Node *num1 = NULL;
	Node *num2 = NULL;
	Node *sum = NULL;

	num1 = addNode(num1, 4);
	num1 = addNode(num1, 9);


	num2 = addNode(num2, 4);
	num2 = addNode(num2, 2);

	display(num1);
	display(num2);

	sum = sumOfNodes(num1, num2);

	display(sum);

	return 0;
}
