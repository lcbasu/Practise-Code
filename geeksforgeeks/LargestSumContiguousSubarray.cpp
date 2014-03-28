#include <iostream>
#include <algorithm>

using namespace std;

int largestSum(int arr[], int n)
{
	int maxSoFar = arr[0];
	int maxEndingHere = arr[0];
	for (int i = 1; i < n; ++i)
	{
		maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}

int main()
{
	int arr[] = {-2, -3, -4, -1, 2, -1, -5, -3};
	cout << largestSum(arr, sizeof(arr)/sizeof(arr[0])) << endl;
	return 0;
}