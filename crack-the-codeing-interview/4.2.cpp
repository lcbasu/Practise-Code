#include <iostream>
#include <list>

using namespace std;


class GraphSearch
{
public:
	GraphSearch(int);
	void addNode(int, int);
	bool bfsRoute(int, int);
private:
	list<int> *adjList;
	int V;
};

GraphSearch::GraphSearch(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}

void GraphSearch::addNode(int src, int dest)
{
	adjList[src].push_back(dest);
}

bool GraphSearch::bfsRoute(int src, int dest)
{
	bool *visited = new bool[V];
	for (int i = 0; i < V; ++i)
	{
		visited[i] = false;
	}

	list<int> queue;
	visited[src] = true;
	queue.push_back(src);
	while(!queue.empty())
	{
		int currentNode = queue.front();
		cout << "At : " << currentNode << endl;
		queue.pop_front();
		list<int>::iterator it;
		for(it = adjList[currentNode].begin(); it != adjList[currentNode].end(); it++)
		{
			if(!visited[*it])
			{
				if(*it == dest)
					return true;
				visited[currentNode] = true;
				queue.push_back(*it);
			}				
		}
	}
	return false;
}


int main()
{
	GraphSearch g(4);
	g.addNode(0,1);
	g.addNode(1,2);
	g.addNode(0,3);
	g.addNode(2,3);
	g.addNode(2,0);
	if(g.bfsRoute(2,1))
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;
}