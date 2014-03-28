#include <iostream>

using namespace std;

int longesrIncreasingSubsequenceMul(int *arr, int n)
{
	int *result = new int[n];
	for(int i = 0; i < n; i++)
		result[i] = arr[i];

	for(int i = 1; i < n; i++)
	{
		if(arr[i] == 0)
			continue;
		else if(arr[i] < 0)
		{
			for(int j = 0; j < i; j++)
			{
				if(arr[j] < arr[i] && result[i] > arr[i] * result[j])
					result[i] = arr[i] * result[j];
			}
		}
		else	//arr[i] > 0
		{
			for(int j = 0; j < i; j++)
			{
				if(arr[j] < arr[i] && result[i] < arr[i] * result[j])
					result[i] = arr[i] * result[j];
			}
		}
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
  int arr[] = {1, -2, 4, 0};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout <<  longesrIncreasingSubsequenceMul(arr, n) << endl;
  return 0;
}
