#include <iostream>

using namespace std;

struct Node
{
	Node *left;
	Node *right;
	int data;
};

Node *root;

int main()
{
	root = new Node();
	root->data = 72;
	root->left = new Node();
	root->left->data = 31;
	root->left->left = NULL;
	root->left->right = NULL;
	root->right = new Node();
	root->right->data = 84;
	root->right->left = NULL;
	root->right->right = NULL;

	return 0;
}