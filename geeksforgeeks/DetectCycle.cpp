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
	bool isCyclic();
private:
	list<int> *adjList;
	int V;
	bool isCyclicHelper(int src, bool visited[], bool recusrsionStack[]);
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


bool Graph::isCyclic()
{
	bool *visited = new bool[V];
	bool *recusrsionStack = new bool[V];

	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
		recusrsionStack[i] = false;
	}

	for (int i = 0; i < V; ++i)
	{
		if(isCyclicHelper(i, visited, recusrsionStack))
			return true;
	}
	return false;
}


bool Graph::isCyclicHelper(int src, bool visited[], bool recusrsionStack[])
{
	if(!visited[src])
	{
		visited[src] = true;
		recusrsionStack[src] = true;
		list<int>::iterator it;
		for(it = adjList[src].begin(); it != adjList[src].end(); it++)
		{
			if(!visited[*it] && isCyclicHelper(*it, visited, recusrsionStack))
				return true;
			else if(recusrsionStack[*it])
				return true;
		}
	}
	recusrsionStack[src] = false;
	return false;
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

    if(g.isCyclic())
    	cout << "Cyclic" << endl;
    else
    	cout << "Acyclic" << endl;

	return 0;
}
