#include <iostream>

using namespace std;

int findLIS(int arr[], int n)
{
	int *LIS = new int[n];
	for (int i = 0; i < n; ++i)
	{
		LIS[i] = 1;
	}
	for (int i = 1; i < n; ++i)
	{
		int max = 0;
		for(int j = 0; j < i; j++)
		{
			if((arr[j] < arr[i]) && (max < LIS[j]))
				max = LIS[j];
		}
		LIS[i] = 1 + max;
	}
	int finalMax = -1;
	for (int i = 0; i < n; ++i)
	{
		if(LIS[i] > finalMax)
			finalMax = LIS[i];
	}
	return finalMax;
}

int main()
{
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << findLIS(arr, n) << endl;
	return 0;
}