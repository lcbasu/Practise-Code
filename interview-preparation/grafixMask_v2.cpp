#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

bool filled[400][600];

struct Node
{
	int x;
	int y;
};

Node *newNode(int x, int y)
{
	Node *tmp = new Node();
	cout << "Address of the newly created Node is : " << tmp << endl;
	tmp->x = x;
	tmp->y = y;
	cout << "New Node created with co-ordinates(x,y) : (" << tmp->x << "," << tmp->y << ")." << endl;
	return tmp;
}

int doFill(int x, int y)
{
	stack<Node *> st;
	int result = 0;
	st.push(newNode(x,y));
	cout << "Address of the Top Node is : " << st.top() << endl;
	while(!st.empty())
	{
		Node *currentTop = st.top();
		st.pop();
		cout << "Top x : " << currentTop->x << endl;
		cout << "Top y : " << currentTop->y << endl;
		if(currentTop->x < 0 || currentTop->x >= 600 || currentTop->y < 0 || currentTop->y >= 400)
			continue;
		if(filled[currentTop->y][currentTop->x])
			continue;
		filled[currentTop->y][currentTop->x] = true;
		result++;
		st.push(newNode(currentTop->x + 1,currentTop->y));
		st.push(newNode(currentTop->x - 1,currentTop->y));		
		st.push(newNode(currentTop->x,currentTop->y + 1));
		st.push(newNode(currentTop->x,currentTop->y - 1));
	}
	return result;
}

int main()
{
	vector<int> result;
	for (int i = 0; i < 400; i++)
	{
		for(int j = 0; j < 600; j++)
		{
			filled[i][j] = false;
		}
	}

	//	0 292 399 307

	for (int i = 0; i <= 399; i++)
	{
		for(int j = 292; j <= 307; j++)
		{
			filled[i][j] = true;
		}
	}

	for (int i = 0; i < 400; i++)
	{
		for(int j = 0; j < 600; j++)
		{
			if(filled[i][j] == false)
				result.push_back(doFill(j,i));
		}
	}

	sort(result.begin(), result.end());

	cout << "Final Result:" << endl;
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}

	cout << endl;

	return 0;
}