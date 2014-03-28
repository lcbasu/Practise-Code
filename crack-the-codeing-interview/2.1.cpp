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
	if(head != NULL)
	{
		newNode->next = head;
	}
	head = newNode;
	return head;
}


void removeDuplicates(Node *head)
{
	if(head == NULL || head->next == NULL)
		return;
	Node *curr = head;
	Node *prev = curr;
	Node *succ = curr->next;
	while(curr != NULL)
	{
		while(succ != NULL)
		{
			if(succ->data == curr->data)
			{
				prev->next = succ->next;
				delete succ;
				succ = prev->next;
			}
			else
			{
				succ = succ->next;
				prev = prev->next;
			}			
		}
		curr = curr->next;
		if(curr != NULL)
		{
			prev = curr;
			succ = curr->next;
		}
	}
}


int main()
{
	Node *head = NULL;
	head = addNode(head, 3);
	head = addNode(head, 1);
	head = addNode(head, 7);
	head = addNode(head, 2);
	head = addNode(head, 4);
	head = addNode(head, 32);
	head = addNode(head, 27);
	head = addNode(head, 1);
	head = addNode(head, 7);
	head = addNode(head, 2);
	head = addNode(head, 4);	
	head = addNode(head, 3);
	head = addNode(head, 1);
	head = addNode(head, 7);
	head = addNode(head, 2);
	head = addNode(head, 4);
	head = addNode(head, 32);
	head = addNode(head, 27);
	head = addNode(head, 1);
	head = addNode(head, 7);
	head = addNode(head, 2);
	head = addNode(head, 4);		
	display(head);
	removeDuplicates(head);
	display(head);
	return 0;
}