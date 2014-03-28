#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>

using namespace std;

struct Edge
{
	int src;
	int dest;
};

struct Graph
{
	int V;	//number of vertices
	int E;	//number of edges

	Edge *edge;
};


Graph *createGraph(int V, int E)
{
	Graph *graph = new Graph;
	graph->V = V;
	graph->E = E;

	graph->edge = new Edge[E];

	return graph;
}
int findSet(int parent[], int i)
{
	if(parent[i] == -1)
		return i;
	return findSet(parent, parent[i]);
}

void unionSet(int parent[], int x, int y)
{
	int xSet = findSet(parent, x);
	int ySet = findSet(parent, y);

	parent[xSet] = ySet;
}


bool isCycle(Graph *graph)
{
	int *parent = (int*)malloc(graph->V * sizeof(int));

	memset(parent, -1, graph->V * sizeof(parent));

	for (int i = 0; i < graph->E; ++i)
	{
		int x = findSet(parent, graph->edge[i].src);
		int y = findSet(parent, graph->edge[i].dest);

		if(x == y)
			return true;
		unionSet(parent, x, y);
	}
	return false;
}



int main()
{
	Graph *g = createGraph(3, 2);

	g->edge[0].src = 0;
	g->edge[0].dest = 1;

	g->edge[1].src = 1;
	g->edge[1].dest = 2;

	//g->edge[2].src = 2;
	//g->edge[2].dest = 0;

	if(isCycle(g))
		cout << "cyclic\n";
	else
		cout << "acyclic\n";

	return 0;
}
