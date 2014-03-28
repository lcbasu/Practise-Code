#include <iostream>
#include <list>

using namespacestd;

class Graph
{
public:
	Graph(int);
	void addEdge(int, int);
	void displayGraph();
private:
	int nodes;
	list<int> *adjList;
};

Graph::Graph(int V)
{
	nodes = V;
	adjList = new list<int>[nodes];
}

void Graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);
}

