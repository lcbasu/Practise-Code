#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int minDistance(int *arr, int n, int x, int y)
{
	int min = INT_MAX;
	for(int i = 0 ; i < n ; i++)
	{
		for(int j = i+1; j < n; j++)
		{
			if(((arr[i] == x && arr[j] == y) || (arr[i] == y &&arr[j] == x)) && min > abs(i-j))
				min = abs(i-j);
		}
	}
	return min;
}

int main()
{
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 8;

    printf("Minimum distance between %d and %d is %d\n", x, y, minDistance(arr, n, x, y));
    return 0;
}
