#include <iostream>
#include <stack>

using namespace std;

bool adjMatrix[5][5];

int color[5];

bool alreadyFound[5];

bool isSafe(bool adjMatrix[5][5], int  colorType, int vertex)
{
	for (int i = 0; i < 5; ++i)
	{
		if(adjMatrix[vertex][i] && color[i] == colorType)
			return false;
	}
	return true;
}

bool isPossible(bool adjMatrix[5][5], int vertex)
{
	if(vertex == 5)
		return true;
	for (int colorType = 1; colorType <= 2; colorType++)
	{
		if(isSafe(adjMatrix, colorType, vertex))
		{
			color[vertex] = colorType;
			if(isPossible(adjMatrix, vertex+1))
				return true;
			else
				color[vertex] = 0;
		}
	}
	return false;
}

int nComponents(bool adjMatrix[5][5])
{
	int count = 0;
	for (int i = 0; i < 5 && !alreadyFound[i]; ++i)
	{
		stack<int> s;
		s.push(i);
				
		while(!s.empty())
		{
			int top = s.top();
			s.pop();
			alreadyFound[top] = true;
			for (int j = 0; j < 5; j++)
			{
				if(adjMatrix[top][j] && !alreadyFound[j])
				{
					//alreadyFound[j] = true;
					s.push(j);
				}
			}
		}
		count++;
	}
	return count;
}

int main()
{
	for (int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 5; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}
	adjMatrix[0][1] = 1;adjMatrix[1][0] = 1;
	adjMatrix[0][3] = 1;adjMatrix[3][0] = 1;
	//adjMatrix[0][4] = 1;adjMatrix[4][0] = 1;
	adjMatrix[1][2] = 1;adjMatrix[2][1] = 1;
	adjMatrix[2][3] = 1;adjMatrix[3][2] = 1;
	//adjMatrix[4][3] = 1;adjMatrix[3][4] = 1;
	for (int i = 0; i < 5; ++i)
	{
		for(int j = 0; j < 5; j++)
		{
			cout << adjMatrix[i][j] << " ";
		}
		cout << endl;
	}

	for (int i = 0; i < 5; ++i)
	{
		color[i] = 0;//non of the vertices are initially colored
	}
	if(isPossible(adjMatrix,0))
		cout << "Yes";
	else
		cout << "No";
	cout << endl;

	for (int i = 0; i < 5; ++i)
	{
		alreadyFound[i] = false;
	}
	cout << "No of components : " << nComponents(adjMatrix) << endl;
	return 0;
}