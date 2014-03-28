#include <stdio.h>
#include <stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* head;

void Insert(int el)
{
	struct Node* tmp = (struct Node*)malloc(sizeof(struct Node));
	tmp->data = el;
	tmp->next = head;
	head = tmp;
}

void Print()
{
	struct Node* tmp = head;
	printf("List is : ");
	while(tmp != 0)
	{
		printf("%d ", tmp->data);
		tmp = tmp->next;
	}
	printf("\n");
}


int main()
{
	head = 0;
	int n, i, el;
	printf("How many numbers : ");
	scanf("%d", &n);
	for (i = 0; i < n; ++i)
	{
		printf("Enter the number : \n");
		scanf("%d", &el);
		Insert(el);
		Print();
	}
	return 0;
}