#include <iostream>
#include <cstdio>

using namespace std;

struct LList
{
	char data;
	LList *next;
};

LList *newNode(char el)
{
	LList *tmp = new LList();
	tmp->data = el;
	tmp->next = NULL;
	return tmp;
}

LList *addToFront(LList *list, char el)
{
	if(list == NULL)
		return newNode(el);
	else
	{
		LList *tmp = newNode(el);
		tmp->next = list;
		return tmp;
	}
}

LList *getLoopEntryNode(LList *list)
{
	LList *slow = list;
	LList *fast = list;
	do
	{
		slow = slow->next;
		fast = fast->next->next;
	}while(slow != fast);

	//now they both have met, so lets start one of the node from begining

	LList *outsideLoopPtr = list;
	LList *insideLoopPtr = slow;	//or fast, because they both are same right now
	while(insideLoopPtr != outsideLoopPtr)
	{
		insideLoopPtr = insideLoopPtr->next;
		outsideLoopPtr = outsideLoopPtr->next;
	}

	return insideLoopPtr;
}

void displayList(LList *list)
{
	printf("\n");
	int i = 0;
	for(LList *tmp = list; tmp != NULL && i < 10; tmp = tmp->next, i++)
		printf("%c\t", tmp->data);
	printf("\n");
}


int main()
{
	LList *list = NULL;
	LList *ptr1, *ptr2;	//ptr1 and ptr2 are used to create loop out of the list like A B C D E F G H I C
	list = addToFront(list, 'I');
	ptr1 = list;
	list = addToFront(list, 'H');
	list = addToFront(list, 'G');
	list = addToFront(list, 'F');
	list = addToFront(list, 'E');
	list = addToFront(list, 'D');
	list = addToFront(list, 'C');
	ptr2 = list;
	list = addToFront(list, 'B');
	list = addToFront(list, 'A');
	
	ptr1->next = ptr2;

	displayList(list);

	LList *loopEntryPoint = getLoopEntryNode(list);
	printf("\nLoop Entry Point :\t%c\n", loopEntryPoint->data);
	return 0;
}