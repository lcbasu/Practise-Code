#include <iostream>

using namespace std;

int LastOcc(int arr[], int n, int k)
{
	int start = 0;
	int end = n-1;
	int lastOcc = -1;
	while(start <= end)
	{
		int mid = start + (end-start)/2;
		if(arr[mid] == k)
		{
			lastOcc = mid;
			start = mid+1;
		}
		else if(arr[mid] > k)
			end = mid-1;
		else
			start = mid+1;
	}
	return lastOcc;
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
		int lastOcc = LastOcc(arr, n, k);
		cout << lastOcc << endl;
	}
	return 0;
}