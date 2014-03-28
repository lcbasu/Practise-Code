// http://www.geeksforgeeks.org/avl-tree-set-1-insertion/

#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
	int height;
};

Node* newNode(int data)
{
	Node *tmp = new Node();
	tmp->data = data;
	tmp->height = 1;		//newly inserted node is normally the leaf node
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

int getHeight(Node *node)
{
	if(node == NULL)
		return 0;
	return node->height;
}

int getBalanceFactor(Node *node)
{
	if(node == NULL)
		return 0;
	return (getHeight(node->left)-getHeight(node->right));
}

Node* rotateRight(Node *y)
{
	Node* x = y->left;
	Node* T2 = x->right;

	//rotating
	x->right = y;
	y->left = T2;

	//updating height
	x->height = max(getHeight(x->left), getHeight(x->right))+1;
	y->height = max(getHeight(y->left), getHeight(y->right))+1;

	return x;
}

Node* rotateLeft(Node *x)
{
	Node* y = x->right;
	Node* T2 = y->left;

	//rotating
	y->left = x;
	x->right = T2;

	//updating height
	x->height = max(getHeight(x->left), getHeight(x->right))+1;
	y->height = max(getHeight(y->left), getHeight(y->right))+1;

	return y;
}

Node* insert(Node* node, int data)
{
	if(node == NULL)
		return (newNode(data));
	if(data < node->data)
		node->left = insert(node->left, data);
	else
		node->right = insert(node->right, data);

	node->height = max(getHeight(node->left), getHeight(node->right))+1;

	int balanceFactor = getBalanceFactor(node);

	//LEFT-LEFT Case

	if(balanceFactor > 1 && data < node->left->data)
	{
		node = rotateRight(node);
	}

	//LEFT-RIGHT Case
	if(balanceFactor > 1 && data > node->left->data)
	{
		node->left = rotateLeft(node->left);
		node = rotateRight(node);
	}

	//RIGHT->RIGHT Case
	if(balanceFactor < -1 && data > node->right->data)
	{
		node = rotateLeft(node);
	}

	//RIGHT->LEFT Case
	if(balanceFactor < -1 && data < node->right->data)
	{
		node->right = rotateRight(node->right);
		node = rotateLeft(node);
	}
	return node;
}


void preOrder(Node* root)
{
	if(root != NULL)
	{
		printf("%d ", root->data);
		preOrder(root->left);
		preOrder(root->right);
	}
}


int main()
{
	Node *root = NULL;

	root = insert(root, 10);
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 40);
	root = insert(root, 50);
	root = insert(root, 25);

	  /* The constructed AVL Tree would be
	            30
	           /  \
	         20   40
	        /  \     \
	       10  25    50
	  */

	printf("Pre order traversal of the constructed AVL tree is \n");
	preOrder(root);

	return 0;
}
