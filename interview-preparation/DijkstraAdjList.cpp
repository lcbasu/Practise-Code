// reference -- http://www.geeksforgeeks.org/greedy-algorithms-set-7-dijkstras-algorithm-for-adjacency-list-representation/

#include <iostream>

using namespace std;

struct AdjListNode
{
	int dest;
	int weight;
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

Graph *createGraph(int V)
{
	Graph *g = new Graph();

	g->V = V;
	g->adjList = new AdjList[V];

	for (int i = 0; i < V; ++i)
	{
		g->adjList[i].head = NULL;
	}

	return g;
}

void addEdge(Graph *g, int src, int dest, int weight)
{
	AdjListNode *newNode = new AdjListNode();
	newNode->dest = dest;
	newNode->weight = weight;
	newNode->next = g->adjList[src].head;
	g->adjList[src].head = newNode;
}

void printGraph(Graph *g)
{ 
	for (int i = 0; i < g->V; ++i)
	{
		AdjListNode *nodePtr = g->adjList[i].head;
		cout << i << " -> ";
		while(nodePtr)
		{
			cout << nodePtr->dest << " (" << nodePtr->weight << ") --> " ;
			nodePtr = nodePtr->next;
		}
		cout << endl;
	}
}

int main()
{
	Graph *g = createGraph(9);

	addEdge(g, 0, 1, 4);
	addEdge(g, 0, 7, 8);
	addEdge(g, 1, 0, 4);
	addEdge(g, 1, 7, 11);
	addEdge(g, 1, 2, 8);
	addEdge(g, 2, 1, 8);
	addEdge(g, 2, 3, 7);
	addEdge(g, 2, 5, 4);
	addEdge(g, 2, 8, 2);
	addEdge(g, 3, 2, 7);
	addEdge(g, 3, 4, 9);
	addEdge(g, 3, 5, 14);
	addEdge(g, 4, 3, 9);
	addEdge(g, 4, 5, 10);
	addEdge(g, 5, 2, 4);
	addEdge(g, 5, 3, 14);
	addEdge(g, 5, 4, 10);
	addEdge(g, 5, 6, 2);
	addEdge(g, 6, 7, 1);
	addEdge(g, 6, 8, 6);
	addEdge(g, 6, 5, 2);
	addEdge(g, 7, 6, 1);
	addEdge(g, 7, 1, 11);
	addEdge(g, 7, 8, 7);
	addEdge(g, 7, 0, 8);
	addEdge(g, 8, 2, 2);
	addEdge(g, 8, 6, 6);
	addEdge(g, 8, 7, 7);

	printGraph(g);	
	return 0;
}