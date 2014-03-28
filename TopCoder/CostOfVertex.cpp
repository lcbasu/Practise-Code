#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctype.h>
#include <cstring>
#include <cstdlib>
#include <math.h>
#include <limits>	// numeric_limits<int>::max() similarly for other

#define V_MAX 50

using namespace std;

bool decreasing(int a, int b)
{
	return a>b;
}

int costOfVertex(bool G[][V_MAX], int W[][V_MAX], int vertexWeights[], int V, int u)
{
	if(vertexWeights[u] >= 0)
		return vertexWeights[u];
	vector<int> tmpWeights;
	for (int v = 0; v < V; v++)
	{
		if(G[u][v])
			tmpWeights.push_back(costOfVertex(G, W, vertexWeights, V, v)+W[u][v]);
	}
	sort(tmpWeights.begin(), tmpWeights.end(), decreasing);
	vertexWeights[u] = tmpWeights[0];
	return vertexWeights[u];
}

int main()
{
	bool G[V_MAX][V_MAX];
	int W[V_MAX][V_MAX];

	int V = 3;

	G[0][0] = 0;
	G[0][1] = 1;
	G[0][2] = 1;
	G[1][0] = 0;
	G[1][1] = 0;
	G[1][2] = 1;
	G[2][0] = 0;
	G[2][1] = 0;
	G[2][2] = 0;

	W[0][0] = 0;
	W[0][1] = 5;
	W[0][2] = 3;
	W[1][0] = 0;
	W[1][1] = 0;
	W[1][2] = 7;
	W[2][0] = 0;
	W[2][1] = 0;
	W[2][2] = 0;

	int *vertexWeights = new int[3];
	vertexWeights[0] = -1;
	vertexWeights[1] = -1;
	vertexWeights[2] = 0;
	

	int maxDis = 0;

	for (int i = 0; i < V; ++i)
	{
		int tmpMax = costOfVertex(G, W, vertexWeights, V, 0);
		if(tmpMax > maxDis)
			maxDis = tmpMax;
	}
	cout << "Maximum Distance : " << maxDis << endl;

	return 0;
}