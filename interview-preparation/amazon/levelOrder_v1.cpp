#include <iostream>
#include <cmath>
#include <algorithm>

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

int height(Node *root)
{
	if(root == NULL)
		return 0;
	return 1+max(height(root->left), height(root->right));
}

void printGivenLevel(Node *root, int level)
{
	if(root == NULL)
		return;
	if(level == 1)
	{
		cout << root->key << " ";
	}
	else if(level > 1)
	{
		printGivenLevel(root->left, level-1);
		printGivenLevel(root->right, level-1);
	}

}

void printLevelOrder(Node *root)
{
	int h = height(root);
	for(int i  = 1; i <= h; i++)
	{
		printGivenLevel(root, i);
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
