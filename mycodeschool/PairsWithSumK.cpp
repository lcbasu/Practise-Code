#include <iostream>

using namespace std;

bool *inMemory;


int pairSum(int arr[], int n, int k)
{
	int count = 0;

	if(n==0)
		return count;
	for (int i = 0; i < n; ++i)
	{
		int start = 0;
		int end = n-1;		
		while(start <= end)
		{
			int mid = start + (end-start)/2;
			if(i == mid)
				break;
			else if((arr[i] + arr[mid]) == k && !inMemory[i] && !inMemory[mid])
			{
				count++;
				inMemory[i] = true;
				inMemory[mid] = true;
			}
			else if(arr[i] + arr[mid] >= k)
			{
				end = mid-1;
			}
			else
				start = mid+1;
		}
	}
	return count;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		int *arr = new int[n];
		inMemory = new bool[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
			inMemory[i] = false;
		}
		cout << pairSum(arr, n, k) << endl;
	}
	return 0;
}