#include <iostream>
#include <algorithm>

using namespace std;

void rearrange(int arr[], int n)
{
	sort(arr, arr+n);
	for(int i = 1; i < n; i = i + 2)
	{
		if(i >= n-1)
			break;
		int tmp = arr[i];
		arr[i] = arr[i+1];
		arr[i+1] = tmp;
	}
}

int main()
{
	int arr[] = {3,7,5,8,4,9};
	int n = 6;
	cout << "Old :\t";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	rearrange(arr, n);

	cout << "New :\t";
	for(int i = 0; i < n; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
	return 0;
}
