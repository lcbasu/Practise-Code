#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(struct Node** headPtr, int el)
{
	struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->data = el;
	tmp->next = *headPtr;
	*headPtr = tmp;
}

void Print(struct Node** headPtr)
{
	printf("List is : ");
	while(*headPtr != 0)
	{
		printf("%d ", (*headPtr)->data);
		(*headPtr) = (*headPtr)->next;
	}
	printf("\n");
}


int main()
{
	struct Node* head = 0;
	int n, i, el;
	printf("How many numbers : ");
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		printf("Enter the number : \n");
		scanf("%d", &el);
		Insert(&head, el);
		Print(&head);
	}
	return 0;
}