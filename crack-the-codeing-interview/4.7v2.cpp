#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *root;

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

void display()
{
	preorder(root);
}

Node *createTree(int arr[], int start, int end)
{
	if(start > end)
		return NULL;
	int mid = (start+end)/2;
	Node *root = newNode(arr[mid]);
	cout << "Entered : " << arr[mid] << endl;
	root->left = createTree(arr, start, mid-1);
	root->right = createTree(arr, mid+1, end);
	return root;
}


Node *leastCommonAncestor(Node *root, int data1, int data2)
{
	if(root == NULL)
		return NULL;
	
}


int main()
{
	int arr[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	root = createTree(arr, 0, sizeof(arr)/sizeof(arr[0])-1);
	display();
	return 0;
}