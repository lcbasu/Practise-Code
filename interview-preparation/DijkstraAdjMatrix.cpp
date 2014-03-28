// reference -- http://www.geeksforgeeks.org/greedy-algorithms-set-6-dijkstras-shortest-path-algorithm/

#include <iostream>
#include <limits>

#define INFI numeric_limits<int>::max()

#define V 9

using namespace std;

int getMinIndex(bool alreadyVisited[V], int dist[V])
{
	int min = INFI;
	int minIndex = 0;
	for (int i = 0; i < V; ++i)
	{
		if(alreadyVisited[i] == false && dist[i] <= min)
		{
			min = dist[i];
			minIndex = i;
		}
	}
	return minIndex;
}


void initializeSingleSource(int adjMatrix[V][V], int source, int dist[V])
{
	for (int i = 0; i < V; ++i)
	{
		dist[i] = INFI;
	}
	dist[source] = 0;
}

void relax(int u, int v, int dist[V], int adjMatrix[V][V])
{
	if((dist[v] > (dist[u] + adjMatrix[u][v])))
	{
		dist[v] = dist[u] + adjMatrix[u][v];
	}
}

void dijkstra(int adjMatrix[V][V], int dist[V], bool alreadyVisited[V], int source)
{
	initializeSingleSource(adjMatrix, source, dist);
	for (int i = 0; i < V; ++i)
	{
		int u = getMinIndex(alreadyVisited, dist);
		alreadyVisited[u] = true;
		for(int v = 0; v < V; v++)
		{
			if(adjMatrix[u][v] > 0)
				relax(u, v, dist, adjMatrix);
		}
	}
}

int main()
{
	int adjMatrix[V][V] = {{0,4,0,0,0,0,0,8,0},
				{4,0,8,0,0,0,0,11,0},
				{0,8,0,7,0,4,0,0,2},
				{0,0,7,0,9,14,0,0,0},
				{0,0,0,9,0,10,0,0,0},
				{0,0,4,13,10,0,2,0,0},
				{0,0,0,0,0,2,0,1,6},
				{8,11,0,0,0,0,1,0,7},
				{0,0,2,0,0,0,6,7,0}};
	int dist[V];
	bool alreadyVisited[V];
	for (int i = 0; i < V; ++i)
	{
		alreadyVisited[i] = false;
		dist[i] = INFI;
	}

	dijkstra(adjMatrix, dist, alreadyVisited, 0);

	cout << "Vertex" << "\t" << "Distance From Source" << endl;
	
	for (int i = 0; i < V; ++i)
	{
		cout << i << "\t" << dist[i] << endl;
	}

	cout << endl;
	return 0;
}