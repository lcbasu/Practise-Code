#include <iostream>
#include <queue>

#define V 4

using namespace std;

bool isBipartite(bool G[][V], int src)
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

int main()
{
	bool G[][V] = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};
	if(isBipartite(G, 0))
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}