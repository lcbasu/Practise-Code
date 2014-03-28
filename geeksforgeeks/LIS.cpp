#include <iostream>

using namespace std;

int longesrIncreasingSubsequence(int *arr, int n)
{
	int *result = new int[n];
	for(int i = 0; i < n; i++)
		result[i] = 1;
	for(int i = 1; i < n; i++)
	{
		int max = 0;
		bool jExists = false;
		for(int j = 0; j < i; j++)
		{
			if(arr[j] < arr[i] && max < result[j])
			{
				max = result[j];
				jExists = true;
			}
		}
		if(jExists)
			result[i] = max+1;
		else
			result[i] = 1;
	}
	int max = 0;
	for(int i = 0; i < n; i++)
	{
		if(max < result[i])
			max = result[i];
	}
	delete(result);
	return max;
}

int main()
{
  int arr[] = { 10, 22, 9, 33, 21, 50, 41, 60, 80 };
  int n = sizeof(arr)/sizeof(arr[0]);
  cout << longesrIncreasingSubsequence(arr, n);
  return 0;
}
