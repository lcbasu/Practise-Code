#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(int V);
	void DFS();
	void addEdge(int src, int dest);
private:
	list<int> *adjList;
	int V;
	void DFSHelper(bool visited[], int src);
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

void Graph::DFS()
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}
	for (int i = 0; i < V; ++i)
	{
		if(!visited[i])
		{
			DFSHelper(visited, i);
		}
		cout << endl;
	}
	delete(visited);
}

void Graph::DFSHelper(bool *visited, int src)
{
	visited[src] = true;
	cout << src << " ";
	list<int>::iterator it;
	for(it = adjList[src].begin(); it != adjList[src].end(); it++)
	{
		if(!visited[*it])
			DFSHelper(visited, *it);
	}

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

    cout << "Following is Depth First Traversal \n";
    g.DFS();
	return 0;
}
