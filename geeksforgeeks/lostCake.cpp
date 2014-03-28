#include <iostream>
#include <cstring>
#include <queue>
#include <list>

using namespace std;

struct Node
{
	int rNo;
	int level;
};

Node *newNode(int rNo, int level)
{
	Node *tmp = new Node();
	tmp->rNo = rNo;
	tmp->level = level;
	return tmp;
}

class Graph
{
	int V;
	list<int> *adjList;
public:
	Graph(int V);
	void addEdge(int u, int v);
	int findPath(int u, int v);
};

Graph::Graph(int V)
{
	this->V = V;
	adjList = new list<int>[V];
}

void Graph::addEdge(int u, int v)
{
	adjList[u].push_back(v);
	if(u != v)
		adjList[v].push_back(u);
}

int Graph::findPath(int s, int d)
{
	if(s == d)
		return 1;

	bool *visited = new bool[V];
	memset(visited, false, sizeof(visited));

	int count = 0;

	list<int>::iterator it;

	queue<Node *> pathNodeQue;

	visited[s] = true;

	int level = 0;

	pathNodeQue.push(newNode(s, level));

	bool found = false;

	while(!pathNodeQue.empty() && !found)
	{
		Node *tmpRoomNode = pathNodeQue.front();
		pathNodeQue.pop();
		for(it = adjList[tmpRoomNode->rNo].begin(); it != adjList[tmpRoomNode->rNo].end(); it++)
		{
			if(!visited[*it])
			{
				if(*it == d)
				{
					count = tmpRoomNode->level + 1;
					found = true;
					break;
				}
				visited[*it] = true;
				pathNodeQue.push(newNode(*it, tmpRoomNode->level+1));
			}
		}
	}
	if(!found)
		return -1;
	return count;
}

int lost_cake(int N, int E, int S, int D, int A[40001], int B[40001])
{
	int V = N + 1;
	Graph g(V);
	for(int i = 0; i < E; i++)
	{
		g.addEdge(A[i], B[i]);
	}
	return g.findPath(S, D);
}

int main()
{
	return 0;
}
