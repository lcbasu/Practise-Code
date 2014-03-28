#include <iostream>

using namespace std;

template<class T>
class BSTNode
{
public:
	T key;
	BSTNode *left, *right;
	BSTNode()
	{
		left = right = 0;
	}
	BSTNode(T el, BSTNode *l=0, BSTNode *r=0)
	{
		key = el;
		left =l;
		right =r;
	}
};

template<class T>
class BST
{
public:
	BST()
	{
		root = 0;
	}
	void insert(T el)
	{
		BSTNode<T> *p = root, *prev =0;
		while(p!=0)
		{
			prev = p;
			if(p->key < el)
				p = p->right;
			else
				p = p->left;
		}
		if(root == 0)
			root = new BSTNode<T>(el);
		else if(prev->key < el)
			prev->right = new BSTNode<T>(el);
		else
			prev->left = new BSTNode<T>(el);
	}

	void print_less_than(int given_key)
	{
		modified_inorder(root, given_key);
	}

private:
	BSTNode<T> *root;
	void modified_inorder(BSTNode<T> *p, int given_key)
	{
		if( p != 0)
		{
			modified_inorder(p->left, given_key);
			if(p->key >= given_key)
				return;
			else
				cout << p->key << "    ";
			modified_inorder(p->right, given_key);
		}
	}
};

int main()
{
	BST<int> bst_obj;
	bst_obj.insert(16);
	bst_obj.insert(14);
	bst_obj.insert(13);
	bst_obj.insert(15);
	bst_obj.insert(19);
	bst_obj.insert(17);
	bst_obj.insert(21);
	bst_obj.insert(22);
	bst_obj.insert(20);
	bst_obj.insert(27);

	bst_obj.print_less_than(17);
	cout << endl;

	return 0;
}