#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(int);
	void addEdge(int, int);
	void DFS();
private:
	int nodes;
	list<int> *adjList;
	void DFSVisit(int, bool *);	
};

Graph::Graph(int V)
{
	nodes = V;
	adjList = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);
}

void Graph::DFSVisit(int v, bool visited[])
{
	cout << v << " ";
	visited[v] = true;

	list<int>::iterator it;
	for(it = adjList[v].begin(); it != adjList[v].end(); it++)
	{
		if(!visited[*it])
			DFSVisit(*it, visited);
	}
}

void Graph::DFS()
{
	bool visited[nodes];
	for (int i = 0; i < nodes; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < nodes; ++i)
	{
		if(!visited[i])
			DFSVisit(i, visited);
	}
}

int main()
{
	Graph graphObj(6);

	graphObj.addEdge(0,1);
	graphObj.addEdge(0,3);
	graphObj.addEdge(1,4);
	graphObj.addEdge(2,5);
	graphObj.addEdge(2,4);
	graphObj.addEdge(3,1);
	graphObj.addEdge(4,3);
	graphObj.addEdge(5,5);
	graphObj.DFS();
	cout << endl;	
	return 0;
}