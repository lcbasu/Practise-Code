#include <iostream>
#include <map>

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
	map<int, int> storeData;
	Node *curr = head->next;
	Node *prev = head;
	while(curr != NULL)
	{
		if(storeData.find(prev->data) == storeData.end())
		{
			storeData[prev->data] = prev->data;
		}

		if(storeData.find(curr->data) != storeData.end())
		{
			prev->next = curr->next;
			delete curr;
			curr = prev->next;
		}
		else
		{
			prev = prev->next;
			curr = curr->next;
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