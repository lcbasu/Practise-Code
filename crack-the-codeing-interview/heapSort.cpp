#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


int parent(int i)
{
	return i/2;
}

int left(int i)
{
	return 2*1;
}

int right(int i)
{
	return ((2*i)+1);
}

void maxHeapify(int arr[], int heapSize, int i)
{
	int l = left(i);
	int r = right(i);
	int largest;
	if(l <= heapSize && arr[l] > arr[i])
		largest = l;
	else
		largest = i;
	if(r <= heapSize && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		maxHeapify(arr, heapSize, largest);
	}
}

void buildMaxHeap(int arr[], int n)
{
	int heapSize = n-1;
	for (int i = n/2; i >= 1; i--)
		maxHeapify(arr, heapSize, i);
}

void heapSort(int arr[], int n)
{
	buildMaxHeap(arr, n);
	int heapSize = n-1;
	for(int i = n-1; i >= 2; i--)
	{
		swap(&arr[1], &arr[i]);
		heapSize = heapSize - 1;
		maxHeapify(arr, heapSize, 1);
	}
}


int main()
{
	int arr[] = {0, 4, 13, 1, 12, 6, 17, 31};
	int n = sizeof(arr)/sizeof(arr[0]);
	heapSort(arr, n);
	cout << "Sorted Array : ";
	for (int i = 1; i < n; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}