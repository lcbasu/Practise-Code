#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define R_MAX 52
#define C_MAX 52

bool isCPC(char mat[R_MAX][C_MAX], int R, int C, int i, int j)
{
	if(mat[i][j] != '^')
		return false;
	if(i-2 < 0 || j-2 < 0 || i+2 >= R || j+2 >= C)
		return false;
	for(int x = -2; x <= 2; x++)
	{
		if(mat[i+x][j] != '^' || mat[i][j+x] != '^')
			return false;
	}
	return true;
}

int main()
{
	int T, R, C;
	scanf("%d", &T);
	while(T--)
	{
		char mat[R_MAX][C_MAX];
		int count = 0;
		scanf("%d %d", &R, &C);

		for (int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				scanf("%c", &mat[i][j]);
			}
		}
		for (int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				if(isCPC(mat, R, C, i, j))
					count++;
			}
		}
		printf("%d\n", count);	
	}
	return 0;
}
