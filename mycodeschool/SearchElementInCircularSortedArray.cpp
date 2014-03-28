#include <iostream>

using namespace std;

int searchElement(int arr[], int n, int k)
{
	int start = 0;
	int end = n-1;
	while(start<=end)
	{
		int mid = start + (end-start)/2;
		if(arr[mid] == k)
			return mid;
		else if(arr[mid] <= arr[end])
		{
			if(k>arr[mid] && k<= arr[end])
				start = mid+1;
			else
				end = mid-1;
		}
		else if(arr[mid] >= arr[start])
		{
			if(k < arr[mid] && k >= arr[start])
				end = mid-1;
			else
				start = mid+1;
		}
	}
}

int main()
{
	int arr[] = {3,4,5,6,1,2};
	cout << searchElement(arr, 6, 2);
	return 0;
}