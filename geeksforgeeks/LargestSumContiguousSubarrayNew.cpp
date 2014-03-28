#include <iostream>

using namespace std;

int max(int a, int b)
{
	return a>b? a:b;
}

int maxSubArraySum(int arr[], int n)
{
	int maxSoFar = arr[0];
	int maxEndingHere = arr[0];
	for (int i = 1; i < n; ++i)
	{
		maxEndingHere = max(arr[i], arr[i] + maxEndingHere);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}

int main()
{
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = sizeof(arr)/sizeof(arr[0]);
	int maxSum = maxSubArraySum(arr, n);
	return 0;
}