#include <iostream>
#include <list>
#include <stack>

using namespace std;

class Graph
{
public:
	Graph(int);
	void addEdge(int, int);
	void topologicalSort();
private:
	int nodes;
	list<int> *adjList;
	void topologicalSortHelp(int, bool *, stack<int> &);
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

void Graph::topologicalSort()
{
	bool visited[nodes];
	for (int i = 0; i < nodes; ++i)
	{
		visited[i] = false;
	}

	stack<int> Stack;
	for (int i = 0; i < nodes; ++i)
	{
		if(!visited[i])
			topologicalSortHelp(i, visited, Stack);
	}
	while(!Stack.empty())
	{
		cout << Stack.top() << " ";
		Stack.pop();
	}
	cout << endl;
}

void Graph::topologicalSortHelp(int v, bool *visited, stack<int> &Stack)
{
	visited[v] = true;
	list<int>::iterator it;
	for(it = adjList[v].begin(); it != adjList[v].end(); it++)
	{
		if(!visited[*it])
			topologicalSortHelp(*it, visited, Stack);
	}
	Stack.push(v);
}


int main()
{
	Graph graphObj(6);
	graphObj.addEdge(5,2);
	graphObj.addEdge(5,0);
	graphObj.addEdge(4,0);
	graphObj.addEdge(4,1);
	graphObj.addEdge(2,3);
	graphObj.addEdge(3,1);
	graphObj.topologicalSort();
	return 0;
}