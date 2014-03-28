#include <iostream>
#include <list>
#include <queue>

using namespace std;

class Graph
{
public:
	Graph(int V);
	void BFS(int src);
	void addEdge(int src, int dest);
	bool isReachable(int src, int dest);
private:
	list<int> *adjList;
	int V;
};

Graph::Graph(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}

void Graph::addEdge(int src, int dest)
{
	adjList[src].push_back(dest);
}

bool Graph::isReachable(int src, int dest)
{
	
}




int main()
{
    // Create a graph given in the above diagram
    Graph g(6);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.addEdge(4, 5);

	return 0;
}
