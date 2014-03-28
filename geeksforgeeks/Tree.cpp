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

void BFT(Node *root)
{
	if(root)
	{
		queue<Node *> que;
		que.push(root);
		while(!que.empty())
		{
			Node *currentNode = que.front();
			que.pop();
			printf("%d ", currentNode->data);
			if(currentNode->left)
				que.push(currentNode->left);
			if(currentNode->right)
				que.push(currentNode->right);
		}
	}
}

//recursive Depth First Search

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


//iterative Depth First Search

void iterativePreorder(Node *root)
{
	if(root)
	{
		stack<Node *> st;
		st.push(root);
		while(!st.empty())
		{
			Node *currentNode = st.top();
			st.pop();
			printf("%d ", currentNode->data);

			//left child has to be pushed after right child because left child has to be printed first
			if(currentNode->right)
				st.push(currentNode->right);
			if(currentNode->left)
				st.push(currentNode->left);
		}
	}
}


void iterativePostorderWithTwoStack(Node *root)
{
	if(root)
	{
		stack<Node *> firstStack;
		stack<Node *> secondStack;
		firstStack.push(root);
		while(!firstStack.empty())
		{
			Node *tmp = firstStack.top();
			firstStack.pop();
			secondStack.push(tmp);
			if(tmp->left)
				firstStack.push(tmp->left);
			if(tmp->right)
				firstStack.push(tmp->right);
		}
		while(!secondStack.empty())
		{
			printf("%d ", secondStack.top()->data);
			secondStack.pop();
		}
	}
}


void iterativeInorder(Node *root)
{
	if(root)
	{
		Node *currentNode = root;
		bool done = false;
		stack<Node *> st;
		while(!done)
		{
			if(currentNode)
			{
				st.push(currentNode);
				currentNode = currentNode->left;
			}
			else
			{
				if(!st.empty())
				{
					currentNode = st.top();
					st.pop();
					printf("%d ", currentNode->data);
					currentNode = currentNode->right;
				}
				else
					done = true;
			}
		}
	}
}


//insertion

void insert(Node *root, int el)
{
	Node *currentNode = root;
	Node *parent = NULL;
	while(currentNode)
	{
		parent = currentNode;
		if(currentNode->data < el)
			currentNode = currentNode->right;
		else
			currentNode = currentNode->left;
	}
	if(root == NULL)
		root = newNode(el);
	else if(el > parent->data)
		parent->right = newNode(el);
	else
		parent->left = newNode(el);
}



/*

deletion cases:

case 1 : No children
case 2 : One Child
case 3 : Two children

*/

void deleteNode(Node *root, int el)
{
	if(root != NULL)
	{
		Node *currentNode = root;
		Node *parent = NULL;
		while(!(currentNode->left->data == el || currentNode->right->data == el) && currentNode != NULL)
		{
			parent = currentNode;
			if(el > currentNode->data)
				currentNode = currentNode->right;
			else
				currentNode = currentNode->left;
		}
		if(currentNode != NULL)
		{
			Node *nodeToBeDeleted = NULL;

			if(currentNode->left->data == el)
			{
				nodeToBeDeleted = currentNode->left;

				//case 1
				if(nodeToBeDeleted->left == NULL && nodeToBeDeleted->right == NULL)
				{
					currentNode->left = NULL;
				}

				//case 2
				else if(nodeToBeDeleted->left == NULL || nodeToBeDeleted->right == NULL)
				{
					if(nodeToBeDeleted->left == NULL)
					{
						currentNode->left = nodeToBeDeleted->right;	
					}
					else
					{
						currentNode->left = nodeToBeDeleted->left;
					}
				}
				delete nodeToBeDeleted;
			}
			else
			{
				nodeToBeDeleted = currentNode->right;

				//case 1
				if(nodeToBeDeleted->left == NULL && nodeToBeDeleted->right == NULL)
				{
					currentNode->right = NULL;
				}

				//case 2
				else if(nodeToBeDeleted->left == NULL || nodeToBeDeleted->right == NULL)
				{
					if(nodeToBeDeleted->left == NULL)
					{
						currentNode->right = nodeToBeDeleted->right;	
					}
					else
					{
						currentNode->right = nodeToBeDeleted->left;
					}
				}
				delete nodeToBeDeleted;
			}
		}
		else
			printf("\nCan't find the desired node.\n");
	}
	else
		printf("\nCouldn't delete from empty tree!\n");
}

// leave at the same level

struct Leaves
{
	Node *node;
	int level;
};

Leaves *newLeaf(Node *node, int level)
{
	Leaves *tmp = new Leaves();
	tmp->node = node;
	tmp->level = level;
	return tmp;
}

void leavesLevelHelper(Node *root, int level, stack<Leaves *> st)
{
	if(root != NULL)
	{
		if(root->left == NULL && root->right == NULL)
		{
			st.push(newLeaf(root, level));
		}
		else
		{
			leavesLevelHelper(root->left, level+1, st);
			leavesLevelHelper(root->right, level+1, st);
		}
	}
}


bool isAllLeavesLevelAtSameLevel(Node *root)
{
	if(root == NULL)
		return true;
	else
	{
		stack<Leaves *> st;
		int level = 0;
		leavesLevelHelper(root, level, st);
		int levelToCheck = st.top()->level;
		while(!st.empty())
		{
			Leaves *top = st.top();
			st.pop();
			if(top->level != levelToCheck)
				return false;
		}
		return true;
	}
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

	//Breadth First Traversal

	printf("Breadth First Traversal : ");
	BFT(root);

	//Recursive Depth First Traversal

	printf("\nRecursive Depth First Traversals\n");
	printf("Preorder :\t");
	preorder(root);
	printf("\nInorder :\t");
	inorder(root);
	printf("\nPostorder :\t");
	postorder(root);
	printf("\nIterative Depth First Traversals\n");
	printf("Preorder :\t");
	iterativePreorder(root);
	printf("\nInorder :\t");
	iterativeInorder(root);
	printf("\nPostorder :\t");
	iterativePostorderWithTwoStack(root);

	//inserting node

	insert(root, 36);
	printf("\nAfter Insertion\nInorder :\t");
	inorder(root);

	deleteNode(root, 36);
	printf("\nAfter Deleting 36\nInorder :\t");
	inorder(root);

	deleteNode(root, 29);
	printf("\nAfter Deleting 29\nInorder :\t");
	inorder(root);

	if(isAllLeavesLevelAtSameLevel(root))
		printf("\nAll leaves are at the same level.\n");
	else
		printf("\nAll leaves are not at the same level.\n");

	return 0;
}
