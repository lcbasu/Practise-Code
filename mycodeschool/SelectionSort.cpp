#include <iostream>

using namespace std;

void SelectionSort(int arr[], int n)
{
	for (int i = 0; i < n-1; i++)
	{
		int minIndex = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[j] < arr[minIndex])
				minIndex = j;
		}
		int tmp = arr[i];
		arr[i] = arr[minIndex];
		arr[minIndex] = tmp;
	}
}

int main()
{
	int arr[] = {2, 7, 3, 1, 8, 6};
	cout << "Before : " << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;	
	SelectionSort(arr,6);
	cout << "After : " << endl;
	for (int i = 0; i < 6; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}