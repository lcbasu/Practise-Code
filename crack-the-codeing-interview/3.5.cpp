#include <iostream>
#include <cstdio>
#include <stack>

using namespace std;

class MyQueue
{
public:
	MyQueue()
	{
		printf("Queue Created.\n");
	}
	void enque(int);
	void dequeue();
	int getFirstEl();
	void manageStacks();

	stack<int> oldStack;
	stack<int> newStack;
};

void MyQueue::enque(int el)
{
	newStack.push(el);
}

void MyQueue::dequeue()
{
	manageStacks();
	if(oldStack.empty())
		printf("Empty Queue!\n");
	else
		oldStack.pop();
}

int MyQueue::getFirstEl()
{
	manageStacks();
	if(oldStack.empty())
	{
		printf("Empty Queue!\n");
		return -1;
	}
	else
		return oldStack.top();
}

void MyQueue::manageStacks()
{
	if(oldStack.empty())
	{
		while(!newStack.empty())
		{
			oldStack.push(newStack.top());
			newStack.pop();
		}
	}
}


int main()
{
	MyQueue mq;

	mq.enque(1);
	mq.enque(2);
	mq.enque(3);
	mq.enque(4);
	mq.enque(5);
	mq.enque(6);
	mq.enque(7);
	mq.enque(8);
	for (int i = 0; i < 8; ++i)
	{
		printf("%d\n", mq.getFirstEl());
	}

	return 0;
}