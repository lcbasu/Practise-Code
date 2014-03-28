#include <iostream>

using namespace std;

int FindOccurance(int arr[], int n, int k, bool first)
{
	int start = 0;
	int end = n-1;
	int findOcc = -1;
	while(start <= end)
	{
		int mid = start + (end-start)/2;
		if(arr[mid] == k)
		{
			findOcc = mid;
			if(first)
				end = mid-1;
			else
				start = mid+1;
		}
		else if(arr[mid] > k)
			end = mid-1;
		else
			start = mid+1;
	}
	return findOcc;
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

		int firstOcc = FindOccurance(arr, n, k, true);
		int lastOcc = FindOccurance(arr, n, k, false);

		if(firstOcc >= 0)
			cout << (lastOcc - firstOcc + 1) << endl;
		else
			cout << 0 << endl;
	}
	return 0;
}