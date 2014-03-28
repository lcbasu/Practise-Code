#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* Insert(struct Node* head, int el)
{
	struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->data = el;
	tmp->next = head;
	head = tmp;
	return head;
}

void Print(struct Node* head)
{
	printf("List is : ");
	while(head != 0)
	{
		printf("%d ", head->data);
		head = head->next;
	}
	printf("\n");
}
void RecursivePrint(struct Node* head)
{
	if(head==0)
		return;
	printf("%d ", head->data);
	RecursivePrint(head->next);
}


void RecursiveReversePrint(struct Node* head)
{
	if(head==0)
		return;
	RecursivePrint(head->next);
	printf("%d ", head->data);
}

int main()
{
	struct Node*  head = 0;
	int n, i, el;
	printf("How many numbers : ");
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		printf("Enter the number : \n");
		scanf("%d", &el);
		head = Insert(head, el);
		Print(head);
	}

	printf("Recursive Reverse Print : ");
	RecursiveReversePrint(head);
	printf("\n");
	return 0;
}