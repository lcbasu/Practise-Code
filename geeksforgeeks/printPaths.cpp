#include <iostream>
#include <queue>
#include <stack>
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
	if(root)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}

void inorder(Node *root)
{
	if(root)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}


void postorder(Node *root)
{
	if(root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

void printThisPath(int arr[], int len)
{
	for (int i = 0; i < len; ++i)
	{
		printf("%d\t", arr[i]);
	}
	printf("\n");
}

void printPathsHelper(Node *root, int arr[], int len)
{
	if(root == NULL)
		return;
	arr[len] = root->data;
	len++;
	if(root->left == NULL && root->right == NULL)
	{
		printThisPath(arr, len);
	}
	printPathsHelper(root->left, arr, len);
	printPathsHelper(root->right, arr, len);
}


void printPaths(Node *root)
{
	int arr[1000];
	int len = 0;
	printPathsHelper(root, arr, len);
}



int main()
{
	Node *root;
	root = newNode(13);
	root->left = newNode(10);
	root->left->left = newNode(2);
	root->left->right = newNode(12);
	root->right = newNode(25);
	root->right->left = newNode(20);
	root->right->right = newNode(31);
	root->right->right->left = newNode(29);

	//Recursive Depth First Traversal

	printf("Recursive Depth First Traversals\n");
	printf("Preorder :\t");
	preorder(root);
	printf("\nInorder :\t");
	inorder(root);
	printf("\nPostorder :\t");
	postorder(root);
	printf("\n");

	printf("All paths\n");
	printPaths(root);

	return 0;
}
