#include <iostream>
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
	return max(1+height(root->left), 1+height(root->right));
}

int diameter(Node *root)
{
	if(root == NULL)
		return 0;
	int lHeight = height(root->left);
	int rHeight = height(root->right);

	int lDiameter = diameter(root->left);
	int rDiameter = diameter(root->right);

	return max(lHeight+rHeight+1, max(lDiameter, rDiameter));
}


int main()
{
	Node *root = newNode(1);
	root->left        = newNode(2);
	root->right       = newNode(3);
	root->left->left  = newNode(4);
	root->left->right = newNode(5);
	root->left->right->right = newNode(51);
	root->left->right->right->right = newNode(52);

	root->left->right->left = newNode(6);
	root->left->right->left->left = newNode(7);

	cout << diameter(root) << endl;

	return 0;
}
