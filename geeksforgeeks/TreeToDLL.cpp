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

Node *extractLeaf(Node *root, Node **head)
{
	if(root == NULL)
		return NULL;
	if(root->left == NULL && root->right == NULL)
	{
		root->right = *head;
		if(*head != NULL)
			(*head)->left = root;
		*head = root;
		return NULL;
	}
	root->right = extractLeaf(root->right, head);
	root->left = extractLeaf(root->left, head);
	return root;
}

void displayDLL(Node *head)
{
	while(head != NULL)
	{
		cout << head->data << " ";
		head = head->right;
	}
	cout << endl;
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


	Node *head = NULL;

	printf("Preorder :\t");
	preorder(root);


	printf("\n\n");

	cout << "After extraction:\n";
	root = extractLeaf(root, &head);
	printf("Preorder :\t");
	preorder(root);
	printf("\n");
	printf("DLL :\t");
	displayDLL(head);

	return 0;
}
