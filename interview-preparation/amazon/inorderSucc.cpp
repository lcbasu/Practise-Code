#include <iostream>

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

Node *minNode(Node *root)
{
	Node *min = NULL;
	while(root != NULL)
	{
		min = root;
		root = root->left;
	}
	return min;
}

Node *inOrderSucc(Node *root, Node *node)
{
	if(node->right != NULL)
		return minNode(node->right);
	Node *succ = NULL;
	while(root != NULL)
	{
		if(root->key > node->key)
		{
			succ = root;
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	return succ;
}

int main()
{
	Node *root = newNode(23);

	root->left = newNode(15);

	Node *node1 = newNode(30);
	root->right = node1;

	root->left->left = newNode(10);
	root->left->right = newNode(21);


	Node *node2 = newNode(17);

	root->left->right->left = node2;


	Node *node3 = newNode(35);
	root->right->right = node3;

	Node *inSucc = inOrderSucc(root, node3);

	if(inSucc != NULL)
		cout << inSucc->key << endl;
	else
		cout << "DNE" << endl;

	return 0;
}
