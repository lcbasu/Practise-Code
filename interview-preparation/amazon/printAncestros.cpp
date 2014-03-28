#include <iostream>

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


bool printAncestors(Node *root, int target)
{
	if(root == NULL)
		return false;
	if(root->key == target)
		return true;
	if(printAncestors(root->left, target) || printAncestors(root->right, target))
	{
		cout << root->key << endl;
		return true;
	}
	return false;
}

int main()
{
	Node *root = newNode(23);

	root->left = newNode(15);
	root->right = newNode(30);

	root->left->left = newNode(10);
	root->left->right = newNode(21);

	root->left->right->left = newNode(17);

	root->right->right = newNode(35);

	printAncestors(root, 35);

	return 0;
}
