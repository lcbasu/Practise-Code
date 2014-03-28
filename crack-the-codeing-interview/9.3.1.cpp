#include <iostream>

using namespace std;

int magicIndex(int arr[], int start, int end)
{
	if(start < end)
	{
		int midIndex = (start + end)/2;
		if(arr[midIndex] == midIndex)
			return midIndex;
		if(arr[midIndex] < midIndex)
			magicIndex(arr, midIndex+1, end);
		if(arr[midIndex] > midIndex)
			magicIndex(arr, start, midIndex-1);
	}
	return -1;
}


int main()
{
	int arr[] = {-2, 0, 2, 11, 13, 14};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << magicIndex(arr, 0, n-1) << endl;
	return 0;
}