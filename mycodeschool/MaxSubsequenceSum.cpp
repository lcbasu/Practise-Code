#include <iostream>

#define NEGINFY -999999999

using namespace std;

int crossSeqSum(int arr[], int start, int mid, int end)
{
	int rightCrossSum = NEGINFY;
	int sum = 0;
	for (int i = mid; i >= start; i--)
	{
		sum += arr[i];
		if(sum > rightCrossSum)
			rightCrossSum = sum;
	}
	int leftCrossSum = NEGINFY;
	sum = 0;
	for (int i = mid+1; i <= end; i++)
	{
		sum += arr[i];
		if(sum > leftCrossSum)
			leftCrossSum = sum;
	}
	return rightCrossSum+leftCrossSum;
}

int maxSubsequenceSum(int arr[], int start, int end)
{
	if(start == end)
		return arr[start];
	int mid = (start+end)/2;
	int leftSum = 0;
	int rightSum = 0;
	int crossSum = 0;
	leftSum = maxSubsequenceSum(arr, start, mid);
	rightSum = maxSubsequenceSum(arr, mid+1, end);
	crossSum = crossSeqSum(arr, start, mid, end);
	if(leftSum > rightSum && leftSum > crossSum)
		return leftSum;
	else if(rightSum > leftSum && rightSum > crossSum)
		return rightSum;
	else
		return crossSum;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << maxSubsequenceSum(arr, 0, n-1) << endl;
	}
	return 0;
}