#include <iostream>
#include <cstring>
#include <list>

using namespace std;

class Graph
{
	int V;
	list<int> *adjList;
	bool isCyclicHelper(int v, bool *visited, bool *recStack, int *vertexInCycle);
public:
	Graph(int V);
	void addEdge(int u, int v);
	bool isCyclic(int *cycleCount, int *totalVertexInCycle);
};


Graph::Graph(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	if(u != v)
		adjList[u].push_back(v);
}

bool Graph::isCyclic(int *cycleCount, int *totalVertexInCycle)
{
	bool *visited = new bool[V];
	bool *recStack = new bool[V];
	memset(visited, false, sizeof(visited));
	memset(recStack, false, sizeof(recStack));

	*totalVertexInCycle = 0;

	bool result = false;
	*cycleCount = 0;

	for(int i = 0; i < V; i++)
	{
		if(!visited[i])
		{
			int vertexInCycle = 0;
			if(isCyclicHelper(i, visited, recStack, &vertexInCycle))
			{
				*totalVertexInCycle = *totalVertexInCycle + vertexInCycle;
				(*cycleCount)++;
				result = true;
			}
		}
	}
	return result;
}


bool Graph::isCyclicHelper(int v, bool *visited, bool *recStack, int *vertexInCycle)
{
	if(!visited[v])
	{
		(*vertexInCycle)++;
		visited[v] = true;
		recStack[v] = true;
		list<int>::iterator it;
		for(it = adjList[v].begin(); it != adjList[v].end(); it++)
		{
			if(recStack[*it] == true)
				return true;
			else if(!visited[*it] && isCyclicHelper(*it, visited, recStack, vertexInCycle))
				return true;
		}
	}
	recStack[v] = false;
	return false;
}


int rearrange(int *arr, int n)
{
	//int totalWays = 0;
	Graph g(4);

	for(int i = 0; i < n; i++)
	{
		g.addEdge(i, arr[i]);
	}

	int cycleCount;
	int totalVertexInCycle;

	g.isCyclic(&cycleCount, &totalVertexInCycle);


	return cycleCount+totalVertexInCycle;
}

int main()
{
	int arr[] = {2,1,3,0};
	int n = sizeof(arr)/sizeof(arr[0]);

	cout << "Minimum moves : " << rearrange(arr, n) << endl;

	return 0;
}
