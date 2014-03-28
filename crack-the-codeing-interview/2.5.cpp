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


Node *addNode(Node *head, int el)
{
	Node *newNode = new Node();
	newNode->data = el;
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

Node *sumOfNodes(Node *num1, Node *num2)
{
	if(num1 == NULL)
		return num2;
	if(num2 == NULL)
		return num1;
	int carry = 0;
	int sum = 0;
	Node *sumNodes = NULL;
	while(num1 != NULL && num2 != NULL)
	{
		sum = num1->data + num2->data + carry;
		if(sum>9)
		{
			sumNodes = addNode(sumNodes, sum%10);
			carry = 1;
		}
		else
		{
			sumNodes = addNode(sumNodes, sum);
			carry = 0;
		}
		num1 = num1->next;
		num2 = num2->next;
	}
	if(num1 != NULL)
	{
		while(num1 != NULL)
		{
			sum = num1->data + carry;
			if(sum>9)
			{
				sumNodes = addNode(sumNodes, sum%10);
				carry = 1;
			}
			else
			{
				sumNodes = addNode(sumNodes, sum);
				carry = 0;
			}
			num1 = num1->next;		
		}
	}
	if(num2 != NULL)
	{
		while(num2 != NULL)
		{
			sum = num2->data + carry;
			if(sum>9)
			{
				sumNodes = addNode(sumNodes, sum%10);
				carry = 1;
			}
			else
			{
				sumNodes = addNode(sumNodes, sum);
				carry = 0;
			}
			num2 = num2->next;		
		}
	}
	if(carry == 1)
	{
		sumNodes = addNode(sumNodes, 1);
	}
	return sumNodes;	
}


int main()
{
	Node *num1 = NULL;
	Node *num2 = NULL;
	Node *sum = NULL;

	num1 = addNode(num1, 4);
	num1 = addNode(num1, 9);
	num1 = addNode(num1, 9);
	num1 = addNode(num1, 9);

	num2 = addNode(num2, 4);
	num2 = addNode(num2, 2);

	display(num1);
	display(num2);

	sum = sumOfNodes(num1, num2);

	display(sum);

	return 0;
}