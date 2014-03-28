#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

void displayStack(stack<int> st, int stNo)
{
	if(st.empty())
	{
		printf("Stack %d is Empty!\n", stNo);
		return;
	}
	printf("Contents of Stack %d are :\t", stNo);
	while(!st.empty())
	{
		printf("%d ", st.top());
		st.pop();
	}
	printf("\n");
}


void TowerOfHanoi(int n, stack<int> *origin, stack<int> *destination, stack<int> *buffer)
{
	if(n <= 0)
		return;
	TowerOfHanoi(n-1, origin, buffer, destination);

	//moving nth peg

	(*destination).push((*origin).top());
	(*origin).pop();

	TowerOfHanoi(n-1, buffer, destination, origin);
}


int main()
{
	stack<int> T1;
	stack<int> T2;
	stack<int> T3;
	for (int i = 5; i > 0; i--)
	{
		T1.push(i);
	}

	printf("Before\n");

	displayStack(T1, 1);
	displayStack(T2, 2);
	displayStack(T3, 3);

	TowerOfHanoi(5, &T1, &T3, &T2);

	printf("\nAfter\n");

	displayStack(T1, 1);
	displayStack(T2, 2);
	displayStack(T3, 3);

	return 0;
}
