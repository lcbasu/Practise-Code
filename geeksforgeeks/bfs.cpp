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

void Graph::BFS(int src)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}

	queue<int> que;
	que.push(src);

	visited[src] = true;

	cout << "BFS :\t";

	while(!que.empty())
	{
		int tempSrc = que.front();
		cout << tempSrc << " ";
		que.pop();
		list<int>::iterator it;
		for(it = adjList[tempSrc].begin(); it != adjList[tempSrc].end(); it++)
		{
			if(!visited[*it])
			{
				que.push(*it);
				visited[*it] = true;
			}
		}
	}

	delete(visited);
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
    g.BFS(2);
	return 0;
}
