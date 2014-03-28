#include <iostream>
#include <stack>
#include <vector>

using namespace std;


class SetOfStacks
{
public:
	SetOfStacks(int);
	void push(int);
	int top();
	void pop();
	void displaySetOfStack();

	int capacity;
private:
	vector<stack<int> > sos;
};


SetOfStacks::SetOfStacks(int capacity)
{
	this->capacity = capacity;
}

void SetOfStacks::push(int el)
{
	if(sos.empty() || sos.back().size() == capacity)
	{
		stack<int> st;
		sos.push_back(st);
		sos.back().push(el);
		cout << "Pushed : " << el << endl;
		return;
	}
	sos.back().push(el);
	cout << "Pushed : " << el << endl;
}

int SetOfStacks::top()
{
	if(sos.empty())
	{
		cout << "Empty Stack" << endl;
		return -1;
	}
	return sos.back().top();
}

void SetOfStacks::pop()
{
	if(sos.empty())
	{
		cout << "Empty Stack" << endl;
		return;
	}
	cout << "Popped : " << top() << endl;
	if(sos.back().size() == 1)	//shifting the last stack pointer bcz of null pointer is created after deleting from a stack with just element
	{
		sos.back().pop();
		sos.pop_back();
	}
}

void SetOfStacks::displaySetOfStack()
{
	vector<stack<int> >::iterator it;
	int count = 0;
	for(it = sos.begin(); it != sos.end(); it++)
	{
		cout << "Top of sub stack "  << count++ << " is : " << it->top() << " and the size os the substack is : " << it->size() << endl;
	}
}

int main()
{
	int n;
	cout << "Capacity ? ";
	cin >> n;

	SetOfStacks ss(n);

	ss.push(1);
	ss.push(2);
	ss.push(3);
	ss.push(4);
	ss.push(5);
	ss.push(6);
	ss.push(7);
	ss.push(8);
	ss.push(9);
	ss.displaySetOfStack();

	

	return 0;
}