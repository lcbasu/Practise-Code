#include <iostream>

using namespace std;

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b =tmp;
}

int partition(char arr[], int start, int end)
{
	int x = arr[end];
	int i = start - 1;
	for(int j = start; j <= end-1; j++)
	{
		if(arr[j] <= x)
		{
			i = i + 1;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[end]);
	return i+1;
}

void quickSort(char arr[], int start, int end)
{
	if(start<end)
	{
		int q = partition(arr, start, end);
		quickSort(arr, start, q-1);
		quickSort(arr, q+1, end);
	}
}

int main()
{
	char arr[] = "Lokesh";
	quickSort(arr, 0, 5);
	cout << arr << endl;
	return 0;
}