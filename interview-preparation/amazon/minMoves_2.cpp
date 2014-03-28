#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(int);
	void addEdge(int u, int v);
	int totalWays();
	bool isCyclic(int u, bool *visited, bool *recState, int *noOfNodesInCycle);
private:
	list<int> *adjList;
	int V;
};

Graph::Graph(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	if(u != v)
	{
		adjList[u].push_back(v);
	}
}


int Graph::totalWays()
{
	bool *visited = new bool[V];
	bool *recState = new bool[V];

	for(int i = 0; i < V; i++)
	{
		visited[i] = false;
		recState[i] = false;
	}
	int totalNodes = 0;
	int totalCycle = 0;

	for(int i = 0 ; i < V; i++)
	{
		int tempNoOfNodes = 0;
		if(isCyclic(i, visited, recState, &tempNoOfNodes))
		{
			totalNodes = totalNodes + tempNoOfNodes;
			totalCycle++;
		}
	}
	return totalNodes+totalCycle;
}


bool Graph::isCyclic(int u, bool *visited, bool *recState, int *totalLoopNodes)
{
	if(!visited[u])
	{
		(*totalLoopNodes)++;
		visited[u] = true;
		recState[u] = true;
		list<int>::iterator it;
		for(it = adjList[u].begin(); it != adjList[u].end(); it++)
		{
			if(recState[*it])
			{
				return true;
			}
			else if(!visited[*it] && isCyclic(*it, visited, recState, totalLoopNodes))
			{
				return true;
			}
		}
	}
	recState[u] = false;
	return false;
}


int rearrange(int *arr, int n)
{
	int result = 0;

	Graph g(n);

	for(int i = 0; i < n; i++)
	{
		g.addEdge(i, arr[i]);
	}

	result = g.totalWays();

	return result;
}

int main()
{
	int arr[] = {2,1,3,0};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Minimum moves : " << rearrange(arr, n) << endl;

	return 0;
}
