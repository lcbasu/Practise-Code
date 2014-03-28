#include <iostream>
#include <limits>
#include <cstdlib>

#define SENTINEL	numeric_limits<int>::max()

#define MAX 10000

using namespace std;


void merge(int arr[], int l, int mid, int r)
{
	int lSize = mid - l + 1;
	int rSize = r - mid;

	int *lArr = new int[lSize+1];
	int *rArr = new int[rSize+1];
	int i, j;

	for (i = 0; i < lSize; i++)
	{
		lArr[i] = arr[l+i];
	}

	for(j = 0; j < rSize; j++)
	{
		rArr[j] = arr[mid+1+j];
	}

	lArr[lSize] = SENTINEL;		//last value as infinite to compare
	rArr[rSize] = SENTINEL;		//last value as infinite to compare

	i = 0;
	j = 0;

	for(int k = l; k <= r; k++)
	{
		if(lArr[i] <= rArr[j])
		{
			arr[k] = lArr[i];
			i++;
		}
		else
		{
			arr[k] = rArr[j];
			j++;
		}
	}
}

void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int mid = l + ((r-l)/2);
		mergeSort(arr, l, mid);
		mergeSort(arr, mid+1, r);
		merge(arr, l, mid, r);
	}
}

//	O(nlg(n)) solution


bool findSum1(int arr[], int n, int sum)
{
	mergeSort(arr, 0, n-1);
	int l = 0;
	int r = n-1;

	while(l < r)
	{
		int tempSum = arr[l] + arr[r];
		if(tempSum == sum)
			return true;
		else if(tempSum < sum)
			l++;
		else
			r--;
	}
	return false;
}


//	O(n) solution

bool findSum2(int arr[], int n, int sum)
{
	bool hashMap[MAX] = {false};
	for (int i = 0; i < n; ++i)
	{
		int tempSum = sum - arr[i];
		if(tempSum >= 0 && hashMap[tempSum] == true)
			return true;
		hashMap[arr[i]] = true;
	}
	return false;
}




int main()
{
	int arr[] = {1, 2, 3, 2, 3, 6, 112, 8, 19};
	int n = sizeof(arr)/sizeof(arr[0]);

	int sum = 12;

	if(findSum1(arr, n, sum))
		cout << "True" << endl;
	else
		cout << "False" << endl;

	if(findSum2(arr, n, sum))
		cout << "True" << endl;
	else
		cout << "False" << endl;

	return 0;
}
