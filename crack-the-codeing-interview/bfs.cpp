#include <iostream>
#include <queue>

using namespace std;

template<class T>
class Queue : public queue<T>
{
public:
	void enqueue(T el)
	{
		queue<T>::push(el);
	}
	T dequeue()
	{
		T temp = queue<T>::front();
		queue<T>::pop();
		return temp;
	}
};

template<class T>
class BSTNode
{
public:
	BSTNode *left, *right;
	T key;

	BSTNode()
	{
		left = right = 0;
	}

	BSTNode(T el, BSTNode *l=0, BSTNode *r=0)
	{
		key = el;
		left = l;
		right = r;
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
		BSTNode<T> *p = root, *prev;
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
	void bfs()
	{
		bfs_helper(root);
	}
private:
	BSTNode<T> *root;
	void bfs_helper(BSTNode<T> *p)
	{
		if(p!=0)
		{
			Queue<BSTNode<T> *> bfs_que;
			bfs_que.enqueue(p);
			while(!bfs_que.empty())
			{
				BSTNode<T> *temp_node = bfs_que.dequeue();

				if(temp_node->left != 0)
					bfs_que.enqueue(temp_node->left);

				if(temp_node->right != 0)
					bfs_que.enqueue(temp_node->right);

				cout << temp_node->key << "    ";
			}
		}
		else
			cout << "Tree is empty!\n";
	}
};

int main()
{
	BST<int> bst_obj;
	bst_obj.insert(13);
	bst_obj.insert(10);
	bst_obj.insert(25);
	bst_obj.insert(2);
	bst_obj.insert(12);
	bst_obj.insert(20);
	bst_obj.insert(31);
	bst_obj.insert(29);

	bst_obj.bfs();

	cout << endl;

	return 0;
}