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

int leftChileIndex(int i)
{
	return 2*i+1;
}

int rightChildIndex(int i)
{
	return 2*i+2;
}

void minHeapify(int arr[], int i, int heapSize)
{
	int l = leftChileIndex(i);
	int r = rightChildIndex(i);
	int smallest = i;
	if(l < heapSize && arr[l] < arr[i])
		smallest = l;
	if(l < heapSize && arr[r] < arr[smallest])
		smallest = r;
	if(smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		minHeapify(arr, smallest, heapSize);
	}
}

void buildMinHeap(int arr[], int n)
{
	int heapSize = n;
	for (int i = n/2-1; i >= 0; i--)
		minHeapify(arr, i, heapSize);
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
	buildMinHeap(arr, 10);
	cout << "After : ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;		
	return 0;
}