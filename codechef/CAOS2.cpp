#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define R_MAX 51
#define C_MAX 51

int findL(char arr[R_MAX][C_MAX], int r, int c)
{
	int count = 0;
	for (int i = c-1; i >= 0; i--)
	{
		if(arr[r][i] == '^')
			count++;
		else
			break;
	}
	return count;
}

int findR(char arr[R_MAX][C_MAX], int r, int c, int C)
{
	int count = 0;
	for (int i = c+1; i < C; i++)
	{
		if(arr[r][i] == '^')
			count++;
		else
			break;
	}
	return count;
}

int findT(char arr[R_MAX][C_MAX], int r, int c)
{
	int count = 0;
	for (int i = r-1; i >= 0; i--)
	{
		if(arr[i][c] == '^')
			count++;
		else
			break;
	}
	return count;
}

int findB(char arr[R_MAX][C_MAX], int r, int c, int R)
{
	int count = 0;
	for (int i = r+1; i < R; i++)
	{
		if(arr[i][c] == '^')
			count++;
		else
			break;
	}
	return count;
}

int monsterNo(char arr[R_MAX][C_MAX], int R, int C)
{
	int count = 0;

	for (int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			bool isCPC = true;
			int minNo = min(min(findL(arr, i, j), findR(arr, i, j, C)), min(findT(arr, i, j), findB(arr, i, j, R)));
			if(minNo < 2)
				isCPC = false;
			if(arr[i][j] != '#' && isCPC == true)
				count++;
		}
	}
	return count;
}

int main()
{
	int T, R, C;
	scanf("%d", &T);
	while(T--)
	{
		char arr[R_MAX][C_MAX];
		scanf("%d %d", &R, &C);
		for (int i = 0; i < R; i++)
		{
			for(int j = 0; j < C; j++)
			{
				scanf("%c", &arr[i][j]);
			}
		}
		printf("\n");
		printf("%d\n", monsterNo(arr, R, C));
	}
	return 0;
}
