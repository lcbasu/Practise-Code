#include <iostream>
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

void inorder(Node *root)
{
	if(root != NULL)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}

void addAllGreaterValueHelper(Node *root, int *sumTillNow)
{
	if(root == NULL)
		return;
	addAllGreaterValueHelper(root->right, sumTillNow);
	*sumTillNow = *sumTillNow + root->data;
	root->data = *sumTillNow;
	addAllGreaterValueHelper(root->left, sumTillNow);
}

void addAllGreaterValue(Node *root)
{
	int sumTillNow = 0;
	addAllGreaterValueHelper(root, &sumTillNow);
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

	printf("Old :\t");
	inorder(root);

	printf("\nNew :\t");
	addAllGreaterValue(root);
	inorder(root);
	

	return 0;
}