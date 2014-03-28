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

bool isIdentical(Node *root1, Node *root2)
{
	if(root1 == NULL && root2 == NULL)
		return true;
	if(root1 == NULL || root2 == NULL)
		return false;
	return ((root1->key == root2->key) && (isIdentical(root1->left, root2->right)) && (isIdentical(root1->right, root2->right)));
}

bool isSubTree(Node *tree, Node *subTree)
{
	if(subTree == NULL)
		return true;
	if(tree == NULL)
		return false;
	if(isIdentical(tree, subTree))
		return true;
	return isSubTree(tree->left, subTree) || isSubTree(tree->right, subTree);
}


int main()
{

	Node *T = newNode(26);
	T->right = newNode(31);


	Node *S = newNode(26);
	S->right = newNode(31);

	if(isSubTree(T, S))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;

	return 0;
}
