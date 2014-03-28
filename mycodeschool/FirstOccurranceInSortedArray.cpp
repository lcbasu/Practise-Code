#include <iostream>

using namespace std;

int FirstOcc(int arr[], int n, int k)
{
	int start = 0;
	int end = n-1;
	int firstOcc = -1;
	while(start <= end)
	{
		int mid = start + (end-start)/2;
		if(arr[mid] == k)
		{
			firstOcc = mid;
			end = mid-1;
		}
		else if(arr[mid] > k)
			end = mid-1;
		else
			start = mid+1;
	}
	return firstOcc;
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
		int firstOcc = FirstOcc(arr, n, k);
		cout << firstOcc << endl;
	}
	return 0;
}