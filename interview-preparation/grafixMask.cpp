#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
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
	tmp->x = x;
	tmp->y = y;
	return tmp;
}

vector<int> doFill()
{
	vector<int> result;

	for (int i = 0; i < 400; ++i)
	{
		for(int j = 0; j < 600; j++)
		{
			if(filled[i][j] == false)
			{
				stack<Node *> st;
				int count = 0;
				st.push(newNode(j,i));
				while(!st.empty())
				{
					Node *top = st.top();
					st.pop();
					if(top->x < 0 || top->x >599 || top->y < 0 || top->y > 399)
						continue;
					if(filled[top->y][top->x] == true)
						continue;
					else
					{
						filled[top->y][top->x] == true;
						count++;
						st.push(newNode(top->x+1, top->y));
						st.push(newNode(top->x-1, top->y));
						st.push(newNode(top->x, top->y+1));
						st.push(newNode(top->x, top->y-1));
					}
				}
				result.push_back(count);
			}
		}
	}
	return result;
}


int main()
{
	vector<string> rectangle;
	rectangle.push_back("0 292 399 307");

	stringstream ss;
	ss << rectangle[0];

	int r1, c1, r2, c2;

	ss >> r1 >> c1 >> r2 >> c2;

	for (int i = 0; i < 400; i++)
	{
		for(int j = 0; j < 600; j++)
		{
			if(i >= r1 && i <= r2 && j >= c1 && j <= c2)
			{
				filled[i][j] = true;
			}
			else
			{
				filled[i][j] = false;
			}
		}
	}

	vector<int> result;

	result = doFill();
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}