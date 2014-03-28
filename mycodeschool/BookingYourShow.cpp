#include <iostream>
#include <string>

using namespace std;

int totalPossibleWays(string arr[], int n, int m, int k)
{
	int totalCount = 0;
	for (int i = 0; i < n; i++)
	{
		int tmpCount = 0;
		for(int j = 0; j < m; j++)
		{
			if(arr[i][j] == 'A')
				tmpCount++;
			else if(arr[i][j] == 'X')
				tmpCount = 0;
			if(tmpCount>=k)
				totalCount++;
		}
	}
	return totalCount;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m, k;
		cin >> n >> m >> k;

		string *grid = new string[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> grid[i];
		}

		cout << totalPossibleWays(grid, n, m, k) << endl;

		delete[] grid;
	}
	return 0;
}