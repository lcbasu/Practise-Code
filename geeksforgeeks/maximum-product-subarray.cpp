#include <iostream>
#include <algorithm>

using namespace std;

int longesrIncreasingSubsequenceMul(int *arr, int n)
{
	int maxEndingHere = 1;
	int minEndingHere = 1;

	int maxSoFar = 1;

	for(int i = 0; i < n ; i++)
	{
		if(arr[i] == 0)
		{
			maxEndingHere = 1;
			minEndingHere = 1;
		}
		else if(arr[i] > 0)
		{
			maxEndingHere = maxEndingHere*arr[i];
			minEndingHere = min(minEndingHere*arr[i], 1);
		}
		else	//arr[i] < 0
		{
			int tmp = maxEndingHere;
			maxEndingHere = max(minEndingHere*arr[i], 1);
			minEndingHere = tmp*arr[i];
		}
		if(maxSoFar < maxEndingHere)
			maxSoFar = maxEndingHere;
	}

	return maxSoFar;
}

int main()
{
  int arr[] = {1, -2, -3, 0, 7, -8, -2};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout <<  longesrIncreasingSubsequenceMul(arr, n) << endl;
  return 0;
}
