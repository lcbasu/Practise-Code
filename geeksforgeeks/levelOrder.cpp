/*
Reference

http://www.geeksforgeeks.org/level-order-tree-traversal/


*/

#include <iostream>
#include <cstdio>
#include <queue>

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

void inorder(Node *root)
{
	if (root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void leftViewHelper(Node *root, int level, int *maxLevel)
{
	if(root == NULL)
		return;
	if(level > *maxLevel)
	{
		*maxLevel = level;
		printf("%d ", root->data);
	}
	leftViewHelper(root->left, level+1, maxLevel);
	leftViewHelper(root->right, level+1, maxLevel);
}

void leftView(Node *root)
{
	int maxLevel = 0;
	leftViewHelper(root, 1, &maxLevel);
}


void levelOrder(Node *root)
{
	if(root == NULL)
		return;
	queue<Node *> nodeQueue;
	nodeQueue.push(root);
	while(!nodeQueue.empty())
	{
		Node *tmp = nodeQueue.front();
		printf("%d ", tmp->data);
		nodeQueue.pop();
		if(tmp->left != NULL)
			nodeQueue.push(tmp->left);
		if(tmp->right != NULL)
			nodeQueue.push(tmp->right);		
	}
}


int main()
{
	Node *root;
	root = newNode(12);
	root->left = newNode(10);
	root->right = newNode(30);
	root->right->left = newNode(25);
	root->right->right = newNode(40);
	printf("Tree :\t\t");
	inorder(root);
	printf("\nLeft View :\t");
	leftView(root);
	printf("\nLevel Order :\t");
	levelOrder(root);	
	printf("\n");
	return 0;
}