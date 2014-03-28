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

void sumOfNodesHelper(Node *list1, Node *list2, Node **result, int *carry)
{
	if(list1 == NULL && list2 == NULL)
		return;
	int sum = list1->data + list2->data + *carry;
	*result = addNode(*result, sum%10);
	*carry = sum/10;
	sumOfNodesHelper(list1->next, list2->next, result, carry);
}

Node *sumOfNodes(Node *list1, Node *list2)
{
	if(list1 == NULL)
		return list2;
	if(list2 == NULL)
		return list1;

	Node *result = NULL;

	int carry  = 0;

	sumOfNodesHelper(list1, list2, &result, &carry);

	while(list1 != NULL && list2 == NULL)
	{
		int sum = list1->data + carry;
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
