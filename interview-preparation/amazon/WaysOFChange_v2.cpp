#include <iostream>
#include <cstdio>

using namespace std;

int count(int *arr, int m, int n)
{
	int cache[n+1][m];
	for(int i = 0; i < m; i++)
		cache[0][i] = 1;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 0; j < m; j++)
		{
			int withJ = 0;
			int withoutJ = 0;
			if(i-arr[j] >=0 )
				withJ = cache[i-arr[j]][j];
			if(j-1>=0)
				withoutJ = cache[i][j-1];

			cache[i][j] = withJ+withoutJ;
		}
	}
	return cache[n][m-1];
}

int main()
{
    int arr[] = {1, 2, 3};
    int m = sizeof(arr)/sizeof(arr[0]);
    int n = 400;
    printf(" %d ", count(arr, m, n));
    return 0;
}
