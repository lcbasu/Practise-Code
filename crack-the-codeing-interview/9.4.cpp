#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

void allSubset(int arr[], int n)
{
	for (int i = 1; i < pow(2, n); ++i)
	{
		printf("Subset [%d] :\t", i);
		for(int j = 0 ; j < n; j++)
		{
			if((i & (1<<j)) != 0)
				printf("%d\t", arr[j]);
		}
		printf("\n");
	}
}

int main()
{
	int arr[] = {1,2,3,4};
	int n = sizeof(arr)/sizeof(arr[0]);
	allSubset(arr, n);
	return 0;
}