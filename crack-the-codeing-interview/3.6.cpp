#include <iostream>
#include <stack>
#include <limits>
#include <cstdio>

using namespace std;

int totalCalculation = 0;

stack<int> sortStack(stack<int> st)
{
	stack<int> buff;
	int size = st.size();
	int count = 0;
	while(count != size)
	{
		int smallest = numeric_limits<int>::max();
		for (int i = 0; i < (size-count); ++i)
		{
			if(smallest > st.top())
				smallest = st.top();
			buff.push(st.top());
			st.pop();

		}
		st.push(smallest);
		printf("Pushed :\t%d\n", smallest);cp
		while(!buff.empty())
		{
			if(buff.top() != smallest)
				st.push(buff.top());
			buff.pop();
			totalCalculation++;
		}
		count++;
		totalCalculation++;
	}
	return st;
}

void displayStack(stack<int> st)
{
	while(!st.empty())
	{
		printf("%d\n", st.top());
		st.pop();
	}
}

int main()
{
	stack<int> st;

	st.push(7);
	st.push(2);
	st.push(18);
	st.push(3);
	st.push(21);
	st.push(4);

	displayStack(st);
	st = sortStack(st);
	displayStack(st);
	printf("Total Calculation :\t%d\n", totalCalculation);
	return 0;
}
