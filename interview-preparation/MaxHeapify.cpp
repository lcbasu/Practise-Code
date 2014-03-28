#include <iostream>

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int parentIndex(int i)
{
	return i/2;
}

int leftChildIndex(int i)
{
	return 2*i+1;
}

int rightChildIndex(int i)
{
	return 2*i+2;
}

void maxHeapify(int arr[], int i, int heapSize)
{
	int l = leftChildIndex(i);
	int r = rightChildIndex(i);
	int largest = i;
	if(l < heapSize && arr[l] > arr[i])
		largest = l;
	if(r < heapSize && arr[r] > arr[largest])
		largest = r;
	if(largest != i)
	{
		swap(&arr[i], &arr[largest]);
		maxHeapify(arr, largest, heapSize);
	}
}

void buildMaxHeap(int arr[], int n)
{
	int heapSize = n;
	for(int i = heapSize/2-1; i >= 0; i--)
		maxHeapify(arr, i, heapSize);
}

int main()
{
	int arr[] = {4,1,3,2,16,9,10,14,8,7};
	cout << "Before : ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	buildMaxHeap(arr, 10);
	cout << "After : ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;	
	return 0;
}