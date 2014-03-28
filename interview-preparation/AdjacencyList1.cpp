#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	int V;
	list<int> *adjList;
	Graph(int V)
	{
		this->V = V;
		adjList = new list<int>[V];
	}
	void addEdge(int u, int v);
	void printGraph();
};

void Graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);
}

void Graph::printGraph()
{
	for (int i = 0; i < V; ++i)
	{
		cout << i << " -> ";
		list<int>::iterator it;
		for(it = adjList[i].begin(); it != adjList[i].end(); it++)
		{
			cout << *it << " -> ";
		}
		cout << endl;
	}
}

int main()
{
	Graph newGraph(4);
	newGraph.addEdge(0,1);
	newGraph.addEdge(0,3);
	newGraph.addEdge(1,2);
	newGraph.addEdge(2,1);
	newGraph.addEdge(2,3);
	newGraph.addEdge(3,1);
	newGraph.printGraph();
	return 0;
}