#include <iostream>
#include <algorithm>
#include <limits>
#include <cstdio>

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

void preorder(Node *root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		printf("\n");		
		preorder(root->left);
		preorder(root->right);		
	}
}

void display(Node *root)
{
	preorder(root);
}


bool checkBST(Node *root, int min, int max)
{
	if(root == NULL)
		return true;
	if(root->data <= min && root->data > max)
		return false;
	if(checkBST(root->left, min, root->data) || !checkBST(root->right, root->data, max))
		return false;
	return true;
}


int main()
{
	int max = numeric_limits<int>::max();
	int min = numeric_limits<int>::min();
	Node *root = newNode(17);
	root->left = newNode(10);
	root->right = newNode(23);
	root->left->right = newNode(111);
	display(root);
	if(checkBST(root, min, max))
		printf("Binary Tree is a Binary Search Tree.\n");
	else
		printf("Binary Tree isn't a Binary Search Tree.\n");
	return 0;
}