#include <iostream>
#include <stack>

using namespace std;

stack<int> st;
stack<int> minState;

void push(int el)
{
	if(st.empty())	//if main stack is empty then minState stack will also be empty
	{
		st.push(el);
		minState.push(el);
	}
	else
	{
		if(el < minState.top())
			minState.push(el);
		else
			minState.push(minState.top());
		st.push(el);
	}
}

void pop()
{
	st.pop();
	minState.pop();
}

int min()
{
	return minState.top();
}


int main()
{
	push(3);
	push(17);
	push(2);
	push(11);
	push(4);
	while(!st.empty())
	{
		cout << "Stack Top is:\t" << st.top();
		cout << "\tand the min is : " << min() << endl;
		pop();
	}
	return 0;
}