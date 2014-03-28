#include <iostream>
#include <limits>

using namespace std;

//merge sort
void mergeSort(int*, int, int);
void merge(int*, int, int, int);


//quick sort
void quickSort(int*, int, int);
int partition(int*, int, int);
void swap(int*, int*);



void mergeSort(int *arr, int p, int r)
{
	if(p<r)
	{
		int mid = (p+r)/2;
		mergeSort(arr, p, mid);
		mergeSort(arr, mid+1, r);
		merge(arr, p, mid, r);
	}
}

void merge(int *arr, int p, int mid, int r)
{
	int n1 = r-mid+1;
	int n2 = r-mid;
	int *leftArr = new int[n1+1];
	int *rightArr = new int[n2+1];
	int i;
	for (i = 0; i < n1; i++)
	{
		leftArr[i] = arr[p+i];
	}
	int j;
	for (j = 0; j < n2; j++)
	{
		rightArr[j] = arr[mid+j+1];
	}
	leftArr[n1] = numeric_limits<int>::max();
	rightArr[n2] = numeric_limits<int>::max();
	i = 0;
	j = 0;
	for(int k = p; k <= r; k++)
	{
		if(leftArr[i] <= rightArr[j])
		{
			arr[k] = leftArr[i];
			i++;
		}
		else
		{
			arr[k] = rightArr[j];
			j++;
		}
	}
}

void quickSort(int *arr, int p, int r)
{
	if(p<r)
	{
		int q = partition(arr, p, r);
		quickSort(arr, p, q-1);
		quickSort(arr, q+1, r);
	}
}

int partition(int *arr, int p, int r)
{
	int x = arr[r];
	int i = p - 1;
	for (int j = p; j <= r-1; j++)
	{
		if(arr[j] <= x)
		{
			i = i + 1;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1], &arr[r]);
	return i+1;
}

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


int main()
{
	int arr[] = {7,3,11,2,13};
	cout << "Before :\n";
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	quickSort(arr, 0, 4);
	cout << "After applying Quick Sort:\n";
	for (int i = 0; i < 5; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;	
	return 0;
}