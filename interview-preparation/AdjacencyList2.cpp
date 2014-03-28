//reference -- http://www.geeksforgeeks.org/graph-and-its-representations/

#include <iostream>

using namespace std;

struct AdjListNode
{
	int dest;
	AdjListNode *next;
};


struct AdjList
{
	AdjListNode *head;
};


struct Graph
{
	int V;
	AdjList *adjList;
};

void addEdge(Graph *g, int s, int d)
{
	AdjListNode *newNode = new AdjListNode();
	newNode->dest = d;
	newNode->next = g->adjList[s].head;
	g->adjList[s].head = newNode;
}

void printGraph(Graph *g)
{ 
	for (int i = 0; i < g->V; ++i)
	{
		AdjListNode *nodePtr = g->adjList[i].head;
		cout << i << " -> ";
		while(nodePtr)
		{
			cout << nodePtr->dest << " -> ";
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

int main()
{
	Graph *g = new Graph();
	g->V = 5;
	g->adjList = new AdjList[g->V];
	for (int i = 0; i < g->V; ++i)
	{
		g->adjList[i].head = NULL;
	}
	addEdge(g, 0, 1);
	addEdge(g, 0, 4);
	addEdge(g, 1, 0);
	addEdge(g, 1, 4);
	addEdge(g, 1, 3);
	addEdge(g, 2, 1);
	addEdge(g, 2, 3);
	addEdge(g, 3, 1);
	addEdge(g, 3, 2);
	addEdge(g, 3, 4);
	addEdge(g, 4, 0);
	addEdge(g, 4, 1);
	addEdge(g, 4, 3);
	printGraph(g);
	return 0;
}