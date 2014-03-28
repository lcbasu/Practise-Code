#include <iostream>

using namespace std;

int BinarySearch(int *arr, int start, int end, int k)
{
	int result = -1;
	if(start<=end)
	{
		int mid = start + (end - start)/2;	//(start+end)/2;
		if(arr[mid] == k)
			result = mid;
		else if(arr[mid] > k)
			result = BinarySearch(arr, start, mid-1, k);
		else
			result = BinarySearch(arr, mid+1, end, k);
		return result;
	}
	return result;
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
		int firstOcc = BinarySearch(arr, 0, n-1, k);
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