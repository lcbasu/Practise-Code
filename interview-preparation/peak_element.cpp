#include <iostream>

using namespace std;

int peak(int *arr, int low, int high)
{
	int mid = low + (low+high)/2;
	if(arr[mid] >= arr[mid+1] && arr[mid] >= arr[mid-1])
		return mid;
	else if(arr[mid] < arr[mid-1])
		peak(arr, low, mid-1);
	else if(arr[mid] < arr[mid+1])
		peak(arr, mid+1, high);
}

int main()
{
	int arr[] = {1, 3, 20, 4, 1, 0};
	int n = sizeof(arr)/sizeof(int);
	int index = peak(arr, 0, n-1);
	cout << "Peak element is : " << arr[index] << endl;
	return 0;
}

