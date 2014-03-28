#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(int);
	void addEdge(int, int);
	void DFS(int);
private:
	int V;
	list<int> *adjList;
	void DFSHelper(int, bool []);
};

Graph::Graph(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);
}

void Graph::DFS(int startNode)
{
	bool *visited = new bool[V];
	for(int i = 0; i < V; i++)
		visited[i] = false;
	DFSHelper(startNode, visited);
}

void Graph::DFSHelper(int u, bool visited[])
{
	visited[u] = true;
	cout << u << " ";
	list<int>::iterator it;
	for(it = adjList[u].begin(); it != adjList[u].end(); ++it)
	{
		if(visited[*it] == false)
			DFSHelper(*it, visited);
	}
}

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal (starting from vertex 2) \n";
    g.DFS(2);

	return 0;
}
