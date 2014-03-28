#include <iostream>

using namespace std;

int BinarySearch(int *arr, int n, int k)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = start + (end - start)/2;	//(start+end)/2;
		if(arr[mid] == k)
			return mid;
		else if(arr[mid] > k)
			end = mid-1;
		else
			start = mid+1;
	}
	return -1;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		int firstOcc = BinarySearch(arr, n, k);
		for (int i = firstOcc-1; i >= 0; i--)
		{
			if(arr[i] == arr[firstOcc])
				firstOcc = i;
			else
				break;
		}
		cout << firstOcc << endl;
	}
	return 0;
}