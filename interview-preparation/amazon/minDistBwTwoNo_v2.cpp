#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <climits>

using namespace std;

int minDistance(int *arr, int n, int x, int y)
{
	int prev = 0;
	int min = INT_MAX;
	for(int i = 0; i < n; i++)
	{
		if(arr[i] == x || arr[i] == y)
		{
			prev = i;
			break;
		}
	}

	for(int j = prev; j < n; j++)
	{
		if(arr[j] == x || arr[j] == y)
		{
			if(arr[prev] != arr[j])
			{
				if((j-prev) < min)
				{
					min = j - prev;
					prev = j;
				}
			}
			else
				prev = j;
		}
	}
	return min;
}

int main()
{
    int arr[] = {3, 5, 4, 2, 6, 5, 6, 6, 5, 4, 8, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 3;
    int y = 4;

    printf("Minimum distance between %d and %d is %d\n", x, y, minDistance(arr, n, x, y));
    return 0;
}
