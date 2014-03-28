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

void leftViewHelper(Node *root, int level, int *maxLevel)
{
	if(root == NULL)
		return;
	if(level > *maxLevel)
	{
		cout << root->key << " ";
		*maxLevel = level;
	}
	leftViewHelper(root->left, level+1, maxLevel);
	leftViewHelper(root->right, level+1, maxLevel);
}

void leftView(Node *root)
{
	int maxLevel = 0;
	leftViewHelper(root, 1, &maxLevel);
}

int main()
{
	Node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);

	cout << "Level Order traversal of binary tree is :\t";
	leftView(root);

	return 0;
}
