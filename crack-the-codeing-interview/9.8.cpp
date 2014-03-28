#include <iostream>

using namespace std;

int cache[100];


int totalChange(int arr[], int len, int n, int *count)
{
	if(cache[n] > 0)
		return cache[n];
	if(n<0)
		return 0;
	if(n == 0)
	{
		*count = *count + 1;
		return *count;
	}
	for (int i = 0; i < len; ++i)
	{
		if(arr[i] <= n)
			cache[n] = totalChange(arr, len, n-arr[i], count);
	}
	return cache[n];
}

int main()
{
	for(int i = 0; i < 100; i++)
		cache[i] = -1;
	int arr[4] = {25, 10, 5, 1};
	int count = 0;
	totalChange(arr, 4, 10, &count);
	cout << count << endl;
	return 0;
}
