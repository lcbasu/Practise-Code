#include <iostream>
#include <limits>

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int parentIndex(int i)
{
	if(i == 0)
		return i;
	else if(i%2 !=0)
		return (i-1)/2;
	if(i%2 == 0)
		return (i/2)-1;
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

void buildMaxHeap(int arr[], int heapSize)
{
	for (int i = (heapSize/2)-1; i >= 0; i--)
		maxHeapify(arr, i, heapSize);
}

int heapMax(int arr[])
{
	return arr[0];
}

int heapExtractMax(int arr[], int *heapSizePtr)
{
	if(*heapSizePtr < 1)
	{
		cout << "Heap underflow." << endl;
		return -1;
	}
	int max = arr[0];
	arr[0] = arr[*heapSizePtr-1];
	*heapSizePtr = *heapSizePtr - 1;
	maxHeapify(arr, 0, *heapSizePtr);
	return max;
}

void heapIncreaseKey(int arr[], int i, int key)
{
	cout << "In heapIncreaseKey" << endl;
	if(key < arr[i])
	{
		cout << "New key is lesser than the present key." << endl;
		return;
	}
	arr[i] = key;
	while(i > 0 && arr[parentIndex(i)] < arr[i])
	{
		swap(&arr[i], &arr[parentIndex(i)]);
		i = parentIndex(i);
	}
}

void maxHeapInsert(int arr[], int key, int *heapSizePtr)
{
	*heapSizePtr = *heapSizePtr + 1;
	arr[*heapSizePtr] = numeric_limits<int>::min();
	heapIncreaseKey(arr, *heapSizePtr, key);
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
	int heapSize;
	heapSize = 10;
	buildMaxHeap(arr, heapSize);
	cout << "After : ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Heap Max : " << heapMax(arr) << endl;
	cout << "Heap Max Extracted : " << heapExtractMax(arr, &heapSize) << " and the new heap size is : " << heapSize << endl;
	cout << "After : ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	cout << "Increase the key of bottom-most & rightmost leaf child : ";
	heapIncreaseKey(arr, 8, 333);
	cout << "After : ";
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;		
	return 0;
}