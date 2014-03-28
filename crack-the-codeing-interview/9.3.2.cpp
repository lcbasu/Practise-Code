#include <iostream>
#include <algorithm>

using namespace std;



int magicIndex(int arr[], int start, int end)
{
	if(start < end)
	{
		int midIndex = (start + end)/2;
		if(arr[midIndex] == midIndex)
			return midIndex;

		int leftIndex = min(midIndex-1, arr[midIndex]);
		int leftMagicIndex = magicIndex(arr, start, leftIndex);
		if(leftMagicIndex > 0)
			return leftMagicIndex;

		int rightIndex = max(midIndex+1, arr[midIndex]);
		int rightMagicIndex = magicIndex(arr, rightIndex, end);
		return rightMagicIndex;
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