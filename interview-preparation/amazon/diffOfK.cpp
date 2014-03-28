#include <iostream>
#include <algorithm>

using namespace std;

int exists(int *arr, int toFind, int start, int end)
{
	if(start <= end)
	{
		int mid = start + (end-start)/2;
		if(arr[mid] == toFind)
			return mid;
		else if(arr[mid] < toFind)
			return exists(arr, toFind, mid+1, end);
		else
			return exists(arr, toFind, start, mid-1);
	}
	return -1;
}

int noOfPairs(int *arr, int n, int k)
{
	sort(arr, arr+n);
	int count = 0;
	int start, end = n-1;
	for(int i = 0; i < n; i++)
	{
		int toFind = arr[i] + k;
		start = i+1;
		int resultIndex = exists(arr, toFind, start, end);
		if(resultIndex > 0)
		{
			cout << "Pair is : " << arr[i] << "," << arr[resultIndex] << endl;
			count++;
		}
	}
	return count;
}

int main()
{
	int arr[] = {1,5,3,9,7,15,20,19,13};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 4;
	int pairsCount = noOfPairs(arr, n, k);
	cout << "Total Pairs :\t" << pairsCount << endl;
	return 0;
}