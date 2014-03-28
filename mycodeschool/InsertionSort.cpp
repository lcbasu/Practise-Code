#include <iostream>

using namespace std;

int shiftsDuringInsertionSort(int arr[], int n)
{
	if(n<=1)
		return 0;
	int count = 0;

	for (int i = 1; i < n; ++i)
	{
		int value = arr[i];
		int holeIndex = i;
		bool change = false;
		while(holeIndex > 0 && arr[holeIndex-1] > value)
		{
			arr[holeIndex] = arr[holeIndex-1];
			count++;
			holeIndex--;
			change = true;
		}
		arr[holeIndex] = value;
		if(change)
			count++;
	}
	return count;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}
		cout << shiftsDuringInsertionSort(arr, n) << endl;
	}
	return 0;
}