#include <iostream>
#include <stack>

#define V 4

using namespace std;


int noOfComponents(bool G[][V], int src)
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


int main()
{
	bool G[][V] = {{0, 1, 0, 1}, {1, 0, 1, 0}, {0, 1, 0, 1}, {1, 0, 1, 0}};

	cout << noOfComponents(G, 0) << endl;

	return 0;
}