#include <iostream>

using namespace std;

int binarySearch(int arr[], int start, int end, int x)
{
	if(end < start)
		return -1;
	int mid = start + (end-start)/2;
	if(arr[mid] == x)
		return mid;
	if(arr[mid] < x)
		return binarySearch(arr, mid+1, end, x);
	else
		return binarySearch(arr, start, mid-1, x);
}

int pivotPoint(int arr[], int start, int end)
{
	if(end < start)
		return -1;
	int mid = start + (end-start)/2;	
}

int main()
{
	int arr[] = {2, 2, 2, 3, 5};
	cout << binarySearch(arr, 0, 5, 5) << endl;
	return 0;
}