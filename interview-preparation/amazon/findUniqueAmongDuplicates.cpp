#include <iostream>

using namespace std;

int findUnique(int *arr, int n)
{
	int unique = arr[0];
	for(int i = 1; i < n; i++)
	{
		unique = unique ^ arr[i];
	}
	return unique;
}

int main()
{
	int arr[] = {2, 2, 3, 3, 4, 4, 7, 7, 11, 11, 6, 6, 998876};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << findUnique(arr, n) << endl;
	return 0;
}
