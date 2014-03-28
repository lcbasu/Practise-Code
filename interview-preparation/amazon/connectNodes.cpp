#include <iostream>

using namespace std;

struct Node
{
	char key;
	Node *left;
	Node *right;
	Node *nextRight;
};

Node *newNode(char key)
{
	Node *tmp = new Node;
	tmp->key = key;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

void displayConnection(Node *root)
{
	if(root == NULL)
		return;
	Node *tmp = root;
	for( ; tmp != NULL; tmp = tmp->nextRight)
	{
		cout << tmp->key << " ";
	}
	cout << endl;
	displayConnection(root->left);
}

void connectHelper(Node *root)
{
	if(root == NULL)
		return;

	if(root->left != NULL)
	{
		root->left->nextRight = root->right;
	}
	if(root->right != NULL)
	{
		if(root->nextRight != NULL)
			root->right->nextRight = root->nextRight->left;
		else
			root->right->nextRight = NULL;
	}
	connectHelper(root->left);
	connectHelper(root->right);
}


void connect(Node *root)
{
	root->nextRight = NULL;

	connectHelper(root);
}

int main()
{
	Node *root;
	root = newNode('A');

	root->left = newNode('B');
	root->right = newNode('C');

	root->left->left = newNode('D');
	root->left->right = newNode('E');

	root->right->left = newNode('F');
	root->right->right = newNode('G');

	connect(root);

	displayConnection(root);

	return 0;
}
