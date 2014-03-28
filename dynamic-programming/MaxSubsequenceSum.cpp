#include <algorithm>
#include <iostream>
#include <limits>

using namespace std;

int maxSubsequenceSum(int arr[], int n)
{
	if(n==1)
		return arr[0];
	int sum[n];
	sum[0] = arr[0];
	int maxSum = numeric_limits<int>::min();
	for (int i = 1; i < n; ++i)
	{
		sum[i] = max(sum[i-1]+arr[i], arr[i]);
		if(sum[i] > maxSum)
			maxSum = sum[i];
	}
	return maxSum;
}

int main()
{
	int arr[] = {-2,-3,-4,-1,-2,-1,-5,-3};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << maxSubsequenceSum(arr, n) << endl;
	return 0;
}