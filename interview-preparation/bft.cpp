#include <iostream>
#include <list>

using namespace std;



class Node
{
public:
	Node(int el, Node *l=0, Node *r=0)
	{
		info = el;
		left = l;
		right = r;
	}
	int info;
	Node *left, *right;
};

class Queue
{
public:
	void enQueue(Node *);
	void deQueue();
	int topEl();
	bool isEmpty()
	{
		return queue.empty();
	}
private:
	list<Node *> queue;
};


void Queue::enQueue(Node *n)
{
	queue.push_back(n);
}

void Queue::deQueue()
{
	queue.pop_front();
}

int Queue::topEl()
{
	return queue.front()->info;
}


class Tree
{
public:
	Tree()
	{
		root = 0;
	}
	void addNode(int);
	void BFT(Tree *);
private:
	Node *root;
};

void Tree::addNode(int el)
{
	if(root == 0)
		root = new Node(el);
	else
	{
		Node *temp = root;
		Node *prev;
		while(temp !=0)
		{
			prev = temp;
			if(root->info < el)
				temp = temp->right;
			else if(root->info > el)
				temp = temp->left;
		}
		if(prev->info < el)
			prev->right = new Node(el);
		else if(prev->info > el)
			prev->left = new Node(el);
	}
}

void Tree::BFT(Tree *tr)
{
	if(root == 0)
		return;
	else
	{
		Queue que;
		Node *temp = root;
		que.enQueue(temp);
		while(!que.isEmpty())
		{
			cout << que.topEl()
			if()
		}
	}
}



int main()
{
	return 0;
}