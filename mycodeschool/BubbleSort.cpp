#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int swapsInBubbleSort(int arr[], int n)
{
	if(n<=1)
		return 0;
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		bool noSwapping = true;
		for(int j = 0; j < n-i-1; j++)
		{
			if(arr[j] > arr[j+1])
			{
				noSwapping = false;
				swap(arr[j+1], arr[j]);
				count++;
			}
		}
		if(noSwapping)	//break if any of the pass happened without any swap, that means that the array is already sorted
			break;
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
		cout << swapsInBubbleSort(arr, n) << endl;
	}
	return 0;
}