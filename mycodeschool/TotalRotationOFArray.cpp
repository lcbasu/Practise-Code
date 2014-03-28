#include <iostream>

using namespace std;


int totalRotation(int arr[], int n)
{
	int start = 0;
	int end = n-1;
	if(arr[start] <= arr[end])
		return 0;
	while(start<=end)
	{
		int mid = start + (end-start)/2;
		int next = (mid+1)%n;
		int prev = (mid+n-1)%n;
		if(arr[mid] <= arr[prev] && arr[mid] <= arr[next])
			return mid;
		else if(arr[mid] >= arr[start])
			start = mid+1;
		else if(arr[mid] <= arr[end])
			end = mid-1;
	}
	return 0;
}



int main()
{
	int arr[] = {3,4,5,6,1,2};
	cout << totalRotation(arr, 6);
	return 0;
}