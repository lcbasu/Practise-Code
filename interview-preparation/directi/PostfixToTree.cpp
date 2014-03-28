#include <iostream>
#include <string>

#define MAX 1000

using namespace std;

struct Node
{
	char key;
	Node *left;
	Node *right;
};

Node *newNode(char key)
{
	Node *tmp = new Node();
	tmp->key = key;
	tmp->left = NULL;
	tmp->right = NULL;
	return tmp;
}

bool isLeafNode(Node *node)
{
	if(node->key >= 'a' && node->key <= 'z')
		return true;
	return false;
}

void makeTreeHelp(Node *node, string str, int *index)
{
	if(node->right == NULL)
	{
		node->right = newNode(str[*index]);

		if(isLeafNode(node->right))
		{
			(*index)--;
			makeTreeHelp(node, str, index);
		}
		else
		{
			(*index)--;
			makeTreeHelp(node->right, str, index);
		}
	}
	if(node->left == NULL)
	{
		node->left = newNode(str[*index]);

		if(isLeafNode(node->left))
		{
			(*index)--;
			makeTreeHelp(node, str, index);
		}
		else
		{
			(*index)--;
			makeTreeHelp(node->left, str, index);
		}
	}
}

Node* makeTree(string str)
{
	int index = str.size()-1;
	Node *root = newNode(str[index--]);

	makeTreeHelp(root, str, &index);

	return root;
}

void postorder(Node *root)
{
	if(root != NULL)
	{
		postorder(root->left);
		postorder(root->right);
		cout << root->key << " ";
	}
}

void printPath(char *path, int len)
{
	for(int i = 0; i < len; i++)
	{
		cout << path[i] << "--";
	}
	cout << endl;
}

bool matchExistsInPath(char *path, string str, int level)
{
	if(level+1 < str.size())
		return false;

	int strCount = 0;
	for(int i = 0; i <= level; i++)
	{
		if(path[i] == str[strCount])
			strCount++;
	}

	if(strCount == str.size())
		return true;

	return false;
}

void totalMatchOnPath(Node *node, string str, char *path, int level, int *count)
{
	if(node == NULL)
		return;

	if(node->left == NULL && node->right == NULL)
	{
		path[level] = node->key;
		printPath(path, level+1);
		if(matchExistsInPath(path, str, level))
			(*count)++;
		return;
	}
	path[level] = node->key;
	totalMatchOnPath(node->left, str, path, level+1, count);
	totalMatchOnPath(node->right, str, path, level+1, count);
}

int totalMatch(Node *root, string str)
{
	int count = 0;
	char path[MAX];

	int level = 0;

	totalMatchOnPath(root, str, path, level, &count);

	return count;
}


int main()
{
	Node *root = makeTree("txyBabABA");
	cout << endl;
	postorder(root);
	cout << endl;
	string str = "AA";
	cout << "All the Paths and Count of the matches with :\t" << str << endl;
	cout << "Total Match :\t" << totalMatch(root, str) << endl;
	return 0;
}
