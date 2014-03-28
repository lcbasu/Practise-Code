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


#define V_MAX 60

using namespace std;

class Circuits
{
public:
	int howLong(vector <string> connects, vector <string> costs);
	int costOfVertex(bool G[][V_MAX], int W[][V_MAX], int vertexWeights[], int V, int u);
	int maxDistance(bool G[][V_MAX], int W[][V_MAX], int vertexWeights[], int V);
	void initialWeight(bool G[][V_MAX], int vertexWeights[], int V);
	bool static decreasing(int a, int b);
	int V;
	int *vertexWeights;
};

int Circuits::howLong(vector <string> connects, vector <string> costs)
{
	V = connects.size();
	vertexWeights = new int[V];
	
	bool G[V_MAX][V_MAX];
	int W[V_MAX][V_MAX];

	for (int i = 0; i < V; i++)
	{
		for(int j = 0; j < V; j++)
		{
			G[i][j] = 0;
			W[i][j] = 0;
		}
	}

	for(int i = 0; i < V; i++)
	{
		char buff[100];
		char *s;
		strcpy(buff, connects[i].c_str());
		vector<int> adjVertex;
		for(s = strtok(buff, " "); s; s = strtok(0, " "))
			adjVertex.push_back(atoi(s));

		strcpy(buff, costs[i].c_str());
		vector<int> weights;
		for(s = strtok(buff, " "); s; s = strtok(0, " "))
			weights.push_back(atoi(s));

		while(!adjVertex.empty())
		{
			int v = adjVertex.back();
			int w = weights.back();
			G[i][v] = 1;
			W[i][v] = w;
			adjVertex.pop_back();
			weights.pop_back();
		}
	}
	initialWeight(G, vertexWeights, V);

	return maxDistance(G, W, vertexWeights, V);
}


//initially 0 for vertext having no outbound link and -1 for others
void Circuits::initialWeight(bool G[][V_MAX], int vertexWeights[], int V)
{
	for (int i = 0; i < V; i++)
	{
		int count = 0;
		for(int j = 0; j < V; j++)
		{
			if(G[i][j])
				count++;
		}
		if(count>0)
			vertexWeights[i] = -1;
		else
			vertexWeights[i] = 0;
	}
}


int Circuits::maxDistance(bool G[][V_MAX], int W[][V_MAX], int vertexWeights[], int V)
{
	int maxDis = 0;

	for (int i = 0; i < V; ++i)
	{
		int tmpMax = costOfVertex(G, W, vertexWeights, V, 0);
		if(tmpMax > maxDis)
			maxDis = tmpMax;
	}
	return maxDis;
}

bool Circuits::decreasing(int a, int b)
{
	return a>b;
}

int Circuits::costOfVertex(bool G[][V_MAX], int W[][V_MAX], int vertexWeights[], int V, int u)
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
