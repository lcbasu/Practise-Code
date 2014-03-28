#include <iostream>

using namespace std;

/*
  Print elements of a linked list on console 
  head pointer input could be NULL as well for empty list
  Node is defined as 
  struct Node
  {
     int data;
     struct Node *next;
  }
*/

struct Node
{
	int data;
	Node* next;
};

void Print(Node* head)
{
	if(head == 0)
		return;
	else
	{
		Node* tmp = head;
		while(tmp != 0)
		{
			cout << tmp->data << endl;
			tmp = tmp->next;
		}
	}
}

Node* Insert(Node *head,int data)
{
	Node* tmp = new Node();
	tmp->data = data;
	tmp->next = 0;
	if(head == 0)
		head = tmp;
	else
	{
		Node* t = head;
		while(t->next != 0)
			t = t->next;
		t->next = tmp;
	}
	return head;
}

Node* Insert(Node *head,int data)
{
	Node* tmp = new Node();
	tmp->data = data;
	tmp->next = head;
	head = tmp;
	return head;
}


Node* InsertNth(Node *head,int data, int n) // n is position from beginning
{
	Node* tmp = new Node();
	tmp->data = data;
	tmp->next = 0;
	if(n==1)
	{
		tmp->next = head;
		head = tmp;
		return head;
	}
	Node* t = head;
	for (int i = 0; i < n-2; i++)
	{
		t = t->next;
	}
	tmp->next = t->next;
	t->next = tmp;
	return head;	
}

Node* Delete(Node *head, int n) // n is position from beginning
{
	Node* tmp = head;
	if(n==1)
	{
		head = head->next;
		delete tmp;
		return head;
	}
	for (int i = 0; i < n-2; ++i)
		tmp = tmp->next;
	Node* tmp2 = tmp->next;
	tmp->next = tmp2->next;
	delete tmp2;
	return head;
}

Node* Reverse(Node* head)
{
	Node *p, *current, *n;
	p = 0;
	current = head;
	while(current != 0)
	{
		n = current->next;
		current->next = p;
		p = current;
		current = n;
	}
	head = p;
	return head;
}

int HasLoop(Node* head)
{
	Node* slow = head;
	Node* fast = head;
	while(slow && fast && fast->next != 0)
	{
		slow = slow->next;
		fast = fast->next->next;
		if(slow == fast)
			return 1;
	}
	return 0;
}

int CompareLists(Node *A,Node* B)
{
	while(A != NULL && B != NULL)
	{
		if(A->data != B->data)
			break;
		A = A->next;
		B = B->next;
	}
	if(A == NULL && B == NULL)
		return 1;
	return 0;
}

int GetNthElementFromEnd(Node *head, int n)
{
	Node* tmp = head;
	int count = 0;
	while(tmp != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	tmp = head;
	for (int i = 0; i < (count-n); i++)
	{
		tmp = tmp->next;
	}
	return tmp->data;
}

Node* SortList(Node *head)
{
	if(head == NULL || head->next == NULL)
		return;
	Node *leftList, *rightList;
	split(&leftList, &rightList);
	SortList(leftList);
	SortList(rightList);
	head = merge(&a, &b);
}

void ReversePrint(Node *head)
{
	if(head == 0)
		return;
	ReversePrint(head->next);
	printf("%d\n", head->data);
}

Node* ReverseDLL(Node* head)
{
	Node* tmp = head;
	if(tmp->next == NULL)
	{
		head = tmp;
		return head;
	}
	ReverseDLL(head->next);
	Node* tmp1 = tmp->next;
	tmp->next = tmp->prev;
	tmp->prev = tmp1;
	return head;
}

void RemoveDuplicates(Node *head)
{
	if(head == NULL || head->next == NULL)
		return;

	Node* current;
	Node* succ;	
	current = head;
	succ = head->next;
	while(succ != NULL)
	{
		if(succ->data == current->data)
		{
			current->next = succ->next;
			delete succ;
			succ = current->next;
		}
		else
		{
			current = current->next;
			succ = current->next;
		}
	}
}


/*
    Insert Node in a doubly sorted linked list 
    After each insertion, the list should be sorted
   Node is defined as
   struct Node
   {
     int data;
     Node *next;
     Node *prev
   }
*/


int lengthOfLL(Node *head)
{
	int count = 0;
	for(Node *tmp = head; tmp != NULL; tmp = tmp->next)
		count++;
	return count;
}

int FindMergePointHelper(Node *head1, Node *head2, int diff)
{
	Node *tmp = head1;
	for (int i = 0; i < diff; ++i)
	{
		head1 = head1->next;
	}
	while(head1 != head2)
	{
		head1 = head1->next;
		head2 = head2->next;
	}
	return head1->data;
}

int FindMergePoint(Node *A,Node *B)
{
	int lenA = lengthOfLL(A);
	int lenB = lengthOfLL(B);
	if(lenA>lenB)
		return FindMergePointHelper(A, B, lenA - lenB);
	else
		return FindMergePointHelper(B, A, lenB - lenA);
}


Node* SortedInsert(Node *head,int data)
{
	if(head == NULL)
	{
		Node *tmp = new Node();
		tmp->data = data;
		head = tmp;
		head->next = NULL;
		head->prev = NULL;
	}
	else if(head->data > data)
	{
		Node *tmp = new Node();
		tmp->data = data;
		tmp->next = head;
		head->prev = tmp;
		tmp->prev = NULL;
		head = tmp;
	}
	else
	{
		Node *current = head;
		while(current->next !=0 && current->data < data)
			current = current->next;
		if(current->next == NULL && current->data < data)
		{
			Node *tmp = new Node();
			current->next = tmp;
			tmp->data = data;
			tmp->prev = current;
			tmp->next = NULL;
		}
		else if(current->data >= data)
		{
			Node *tmp = new Node();
			tmp->data = data;
			tmp->next = current;
			tmp->prev = current->prev;
			current->prev = tmp;
			tmp->prev->next = tmp;
		}
	}
	return head;
}



void DeleteKthNode(Node *head, int k)
{
	int i = k;
	Node *tmp = head;
}


int main()
{
	return 0;
}