#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;


int main()
{
	int **m = (int **)malloc(4 * sizeof(int *));
	for (int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; j++)
			m[i][j] = 9;
	}
	for (int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; j++)
			printf("%d", m[i][j]);
		printf("\n");
	}	
	return 0;
}
