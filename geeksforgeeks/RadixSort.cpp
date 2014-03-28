#include <iostream>
#include <cstring>

using namespace std;

int getMax(int arr[], int n)
{
	int maxNo = arr[0];
	for(int i = 1; i < n; i++)
	{
		if(maxNo < arr[i])
			maxNo = arr[i];
	}
	return maxNo;
}

void countingSort(int arr[], int n, int exp)
{
	int count[10];
	int output[n];

	memset(count, 0, sizeof(count));
	for(int i = 0; i < n; i++)
	{
		int countIndex = (arr[i]/exp)%10;
		count[countIndex] += 1;
	}

	for(int i = 1; i < 10; i++)
	{
		count[i] += count[i-1];
	}

	for(int i = n-1; i >= 0; i--)
	{
		int countIndex = (arr[i]/exp)%10;
		int outIndex = count[countIndex]-1;
		output[outIndex] = arr[i];
		count[countIndex] -= 1;
	}

	for(int i = 0; i < n; i++)
		arr[i] = output[i];
}

void radixSort(int arr[], int n)
{
	int m = getMax(arr, n);

	for(int exp = 1; (m/exp)>0; exp = exp * 10)
	{
		countingSort(arr, n, exp);
	}
}

void print(int arr[], int n)
{
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << endl;
}

int main()
{
    int arr[] = {170, 45, 75, 90, 802, 24, 2, 66};
    int n = sizeof(arr)/sizeof(arr[0]);
    radixSort(arr, n);
    print(arr, n);
    return 0;
}
