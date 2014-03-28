#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(int);
	bool isCyclic();
	void addEdge(int, int);
private:
	int V;
	list<int> *adjList;
	bool isCyclicHelper(int, bool[], bool[]);
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

bool Graph::isCyclic()
{
	bool *visited = new bool[V];
	bool *recStack = new bool[V];

	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
		recStack[i] = false;
	}

	for (int i = 0; i < V; ++i)
	{
		if(isCyclicHelper(i, visited, recStack))
			return true;
	}
	return false;
}

bool Graph::isCyclicHelper(int v, bool visited[], bool recStack[])
{
	if(!visited[v])
	{
		visited[v] = true;
		recStack[v] = true;
		list<int>::iterator it;
		for(it = adjList[v].begin(); it != adjList[v].end(); it++)
		{
			if(recStack[*it] == true)	//returned to a vertex which is already in stack
				return true;
			else if(!visited[v] && isCyclicHelper(v, visited, recStack))
				return true;
		}
	}
	recStack[v] = false;
	return false;
}



int main()
{
	Graph g(4);

	g.addEdge(0,1);
	g.addEdge(0,2);
	g.addEdge(1,2);
	g.addEdge(2,0);
	g.addEdge(2,3);
	g.addEdge(3,3);

	if(g.isCyclic())
		cout << "Cyclic\n";
	else
		cout << "Acyclic\n";

	return 0;
}