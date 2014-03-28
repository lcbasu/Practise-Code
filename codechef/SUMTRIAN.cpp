#include <iostream>
#include <algorithm>

using namespace std;

int matrix[100][100];
int cache[100][100];
int n;

int triangleSum(int i, int j)
{
	if(i>=n)
		return 0;
	if(cache[i][j] > 0)
		return cache[i][j];
	int sum1 = triangleSum(i+1,j);
	int sum2 = triangleSum(i+1,j+1);
	int total = max(sum1, sum2) + matrix[i][j];

	cache[i][j] = total;

	return cache[i][j];
}

int main()
{


	int t;
	cin >> t;

	while(t--)
	{
		for (int i = 0; i < 100; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				cache[i][j] = 0;
			}
		}		
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j <= i; j++)
			{
				int tmp;
				cin >> tmp;
				matrix[i][j] = tmp;
			}
		}
		int result = triangleSum(0,0);
		cout << result << endl;
	}
	return 0;
}