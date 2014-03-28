#include <iostream>
#include <cstdio>

using namespace std;

struct Node
{
	int data;
	Node *left;
	Node *right;
};

Node *tree1;
Node *tree2;

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

void display(Node *tree)
{
	preorder(tree);
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

bool matchSubTree(Node *tree1, Node *tree2)
{

}

bool subtreeHelp(Node *tree1, Node *tree2)
{
	if(tree1 == NULL)
		return false;	
	if(tree1->data == tree2->data)
		return matchSubTree(tree1, tree2);
	return (subtreeHelp(tree1->left, tree2) || subtreeHelp(tree1->right, tree2));
}

bool isSubtree(Node *tree1, Node *tree2)
{
	if(tree2 == NULL)
		return true;
	return subtreeHelp(tree1, tree2);
}



int main()
{
	int arr1[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18};
	tree1 = createTree(arr1, 0, sizeof(arr1)/sizeof(arr1[0])-1);
	display(tree1);
	int arr2[] = {1,2,3};
	tree2 = createTree(arr2, 0, sizeof(arr2)/sizeof(arr1[0])-1);
	display(tree2);	
	return 0;
}