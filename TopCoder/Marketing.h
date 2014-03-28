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
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <limits>	// numeric_limits<int>::max() similarly for other


using namespace std;

class Marketing
{
public:
	long long howMany(vector <string> compete);
	bool isBipartite(bool G[][30], int src, int V);
	int noOfComponents(bool G[][30], int src, int V);
};

long long Marketing::howMany(vector <string> compete)
{
	bool G[30][30];
	for (int i = 0; i < 30; ++i)
	{
		for(int j = 0; j < 30; j++)
			G[i][j] = 0;
	}
	int V = compete.size();
	for (int i = 0; i < V; ++i)
	{
		string str = compete[i];
		char buff[100], *s;
		strcpy(buff, str.c_str());
		vector<int> adjVertex;
		for(s = strtok(buff, " "); s ; s = strtok(0, " "))
			adjVertex.push_back(atoi(s));
		while(!adjVertex.empty())
		{
			G[i][adjVertex.back()] = 1;
			G[adjVertex.back()][i] = 1;
			adjVertex.pop_back();
		}
	}
	if(isBipartite(G, 0, V))
		return pow(2, noOfComponents(G, 0, V));
	else
		return -1;
}

bool Marketing::isBipartite(bool G[][30], int src, int V)
{
	int *color = new int[V];
	for (int i = 0; i < V; ++i)
	{
		color[i] = -1;
	}
	queue<int> q;
	q.push(src);
	color[src] = 1;
	while(!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < V; v++)
		{
			if(G[u][v] && color[v] == -1)
			{
				color[v] = 1 - color[u];
				q.push(v);
			}
			else if(G[u][v] && color[v] == color[u])
				return false;
		}
	}
	return true;
}

int Marketing::noOfComponents(bool G[][30], int src, int V)
{
	int componentCount = 0;

	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}

	for (int i = 0; i < V; ++i)
	{
		if(!visited[i])
		{
			stack<int> st;
			st.push(src);

			visited[src] = true;
			while(!st.empty())
			{
				int u = st.top();
				st.pop();
				for (int v = 0; v < V; v++)
				{
					if(G[u][v] && !visited[v])
					{
						visited[v] = true;;
						st.push(v);
					}
				}
			}
			componentCount++;
		}
	}
	return componentCount;
}