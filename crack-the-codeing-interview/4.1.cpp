#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};


Node *newNode(int el)
{
	Node *tmp = new Node();
	tmp->data = el;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}


int height(Node *node)
{
	if(node == NULL)
		return -1;
	return 1 + max(height(node->left), height(node->right));
}


bool isBalanced(Node *root)
{
	if(root == NULL)
		return true;
	int lh = height(root->left);
	int rh = height(root->right);
	if(abs(lh-rh) <= 1 && isBalanced(root->left) && isBalanced(root->right))
		return true;
	return false;
}



int main()
{
	Node *root = newNode(1);
	root->left = newNode(2);
	root->right = newNode(3);
	root->right->left = newNode(6);
	root->left->left = newNode(4);
	root->left->right = newNode(5);
	root->left->left->left = newNode(7);
	root->left->left->left->left = newNode(8);
	cout << "Height of the tree : " << height(root) << endl;
	if(isBalanced(root))
		cout << "Balnced Tree" << endl;
	else
		cout << "Unbalanced Tree" << endl;
	return 0;
}