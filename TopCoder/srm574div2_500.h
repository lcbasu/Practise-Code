#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctype.h>
#include <math.h>
#include <limits>	// numeric_limits<int>::max() similarly for other

using namespace std;

class TheNumberGameDiv2
{
public:
    int minimumMoves(int A, int B)
    {
        if(A == B)
          return 0;
        vector<string> tempStorage;
        stringstream ss;
        ss << A;
        tempStorage.push_back(ss.str());
        ss.str("");
        ss.clear();
        ss << B;
        string strB = ss.str();

    }
};

class TreeNode
{
public:
    TreeNode(int el, TreeNode *l=0, TreeNode *r=0)
    {
        info = el;
        left = l; 
        right = r;
    }
    int info;
    TreeNode *left;
    TreeNode *right;
};

class Tree
{
public:
    Tree()
    {
        root = 0;
    }
    bool isEmpty()
    {
        return head == 0;
    }
    void addEl(int el)
    {
        if (isEmpty())
        {
            root = new TreeNode(el);
        }
        else
          
    }
private:
  TreeNode *root;
};
