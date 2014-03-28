#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(int arr[], int start, int end)
{
	while(start < end)
	{
		int tmp = arr[start];
		arr[start] = arr[end];
		arr[end] = tmp;
		start++;
		end--;
	}
}

int findK(int arr[], int n)
{
	int k;
	for(k = n-2; k >=0; k--)
	{
		if(arr[k] < arr[k+1])
			return k;
	}
	return -1;
}

int findL(int arr[], int n, int k)
{
	for(int l = n-1; l >= 0; l--)
	{
		if(arr[k] < arr[l])
			return l;
	}
}

void printArr(int arr[], int n)
{
	for(int i = 0; i < n ; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}

void lexicographiaclOrdering(int arr[], int n)
{
	printArr(arr, n);
	int k = findK(arr, n);
	while(k != -1)
	{
		int l = findL(arr, n, k);
		swap(&arr[k], &arr[l]);

		reverse(arr, k+1, n-1);

		printArr(arr, n);
		k = findK(arr, n);
	}
}

int main()
{
	int arr[] = {1,2,3};
	int n = sizeof(arr)/sizeof(arr[0]);
	lexicographiaclOrdering(arr, n);
	return 0;
}
