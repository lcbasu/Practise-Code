#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(int V);
	void addEdge(int u, int v);
	list<int>* transpose();
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
	adjList[u].push_back(v);
}

list<int>* Graph::transpose()
{
	list<int> *transposedAL = new list<int>[V];
	for(int i = 0; i < V; i++)
	{
		list<int>::iterator it;
		for(it = adjList[i].begin(); it != adjList[i].end(); it++)
		{
			transposedAL[*it].push_back(i);
		}
	}
	return transposedAL;
}

int main()
{
	Graph *G = new Graph(5);

	G->addEdge(0, 1);
	G->addEdge(1, 2);
	G->addEdge(1, 4);
	G->addEdge(3, 2);

	list<int> *GT = G->transpose();

	for(int i = 0; i < 5; i++)
	{
		list<int>::iterator it;
		cout << i << " ";
		for(it = GT[i].begin(); it != GT[i].end(); it++)
		{
			cout << *it << " ";
		}
		cout << endl;
	}
	return 0;
}