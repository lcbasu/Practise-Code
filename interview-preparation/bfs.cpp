#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
	Graph(int);
	void addEdge(int, int);
	void BFS(int);
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

void Graph::BFS(int source)
{
	bool visited[nodes];
	for (int i = 0; i < nodes; i++)
	{
		visited[i] = false;
	}

	list<int> queue;

	visited[source] = true;
	queue.push_back(source);

	list<int>::iterator it;

	while(!queue.empty())
	{
		int temp = queue.front();
		cout << temp << " ";
		queue.pop_front();
		for(it = adjList[temp].begin(); it != adjList[temp].end(); it++)
		{
			if(visited[*it] == false)
			{
				visited[*it] = true;
				queue.push_back(*it);
			}
		}
	}
}

int main()
{
	Graph graphObj(8);

	graphObj.addEdge(0,1);
	graphObj.addEdge(0,4);
	graphObj.addEdge(1,0);
	graphObj.addEdge(1,5);
	graphObj.addEdge(2,5);
	graphObj.addEdge(2,6);
	graphObj.addEdge(2,3);
	graphObj.addEdge(3,2);
	graphObj.addEdge(3,6);
	graphObj.addEdge(3,7);
	graphObj.addEdge(4,0);
	graphObj.addEdge(5,1);
	graphObj.addEdge(5,2);
	graphObj.addEdge(5,6);
	graphObj.addEdge(6,5);
	graphObj.addEdge(6,2);
	graphObj.addEdge(6,3);
	graphObj.addEdge(6,7);
	graphObj.addEdge(7,3);
	graphObj.addEdge(7,6);
	graphObj.BFS(1);
	cout << endl;
	return 0;
}
