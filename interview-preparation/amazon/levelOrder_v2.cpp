#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

struct Node
{
	int key;
	Node *left;
	Node *right;
};

Node *newNode(int key)
{
	Node *tmp = new Node;
	tmp->key = key;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void printLevelOrder(Node *root)
{
	if(root == NULL)
		return;
	queue<Node *> q;
	q.push(root);
	while(!q.empty())
	{
		Node *tmp = q.front();
		q.pop();
		cout << tmp->key << " ";
		if(tmp->left != NULL)
			q.push(tmp->left);
		if(tmp->right != NULL)
			q.push(tmp->right);
	}
}

int main()
{
	Node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is :\t";
	printLevelOrder(root);

	return 0;
}
