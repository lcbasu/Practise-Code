#include <iostream>
#include <algorithm>

#define M 4
#define N 4

using namespace std;

int fill(int temp[M][N], int arr[M][N], int i, int j)
{
	if(i < 0 || j < 0 || i >= M || j >= N)
		return 0;
	if(temp[i][j] > 0)
		return temp[i][j];
	int up = 0, down = 0, left = 0, right = 0;
	if(arr[i-1][j] == arr[i][j] + 1)
		up = fill(temp, arr, i-1, j);
	if(arr[i+1][j] == arr[i][j] + 1)
		down = fill(temp, arr, i+1, j);
	if(arr[i][j-1] == arr[i][j] +1)
		left = fill(temp, arr, i, j-1);
	if(arr[i][j+1] == arr[i][j] + 1)
		right = fill(temp, arr, i, j+1);
	temp[i][j] = 1 + max(max(up, down), max(left, right));
	return temp[i][j];
}


int main()
{
	int arr[M][N] = {{2, 3, 4, 5},{4, 5, 10, 11}, {20, 6, 9, 12}, {6, 7, 8, 40}};
	int temp[M][N];
	for (int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; j++)
			temp[i][j] = 0;
	}

	for (int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; j++)
		{
			if(temp[i][j] == 0)
			{
				fill(temp, arr, i, j);
			}
		}
	}

	int maxRow = 0, maxCol = 0;

	for (int i = 0; i < M; ++i)
	{
		for(int j = 0; j < N; j++)
		{
			if(temp[i][j] > temp[maxRow][maxCol])
			{
				maxRow = i;
				maxCol = j;
			}
		}
	}
	cout << "Length of LIS :\t" << temp[maxRow][maxCol];
	cout << "\nAnd the LIS :\t";

	int i = maxRow, j = maxCol;

	while(temp[i][j] != 1)
	{
		cout << arr[i][j] << " ";
		if((temp[i-1][j] == temp[i][j] - 1) && (arr[i-1][j] == arr[i][j] + 1))
		{
			i = i - 1;
			cout << arr[i][j] << " ";
			continue;
		}
		if((temp[i+1][j] == temp[i][j] - 1) && (arr[i+1][j] == arr[i][j] + 1))
		{
			i = i + 1;
			cout << arr[i][j] << " ";
			continue;			
		}
		if((temp[i][j-1] == temp[i][j] - 1) && (arr[i][j-1] == arr[i][j] + 1))
		{
			j = j - 1;
			cout << arr[i][j] << " ";
			continue;			
		}
		if((temp[i][j+1] == temp[i][j] - 1) && (arr[i][j+1] == arr[i][j] + 1))
		{
			j = j + 1;
			cout << arr[i][j] << " ";
			continue;			
		}
	}

	return 0;
}