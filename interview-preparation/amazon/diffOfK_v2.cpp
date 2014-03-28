#include <iostream>
#include <cstring>

#define MAX 10000

using namespace std;



int noOfPairs(int *arr, int n, int k)
{
	int count = 0;
	bool bitMap[MAX];
	memset(bitMap, false, sizeof(bitMap));
	for(int i = 0; i < n; i++)
	{
		bitMap[arr[i]] = true;
	}

	for(int i = 0; i < n; i++)
	{
		if(bitMap[arr[i]+k] == true)
		{
			cout << "Pair is : " << arr[i] << "," << arr[i]+k << endl;
			count++;
		}
	}

	return count;
}

int main()
{
	int arr[] = {1,5,3,9,7,15,20,19,13};
	int n = sizeof(arr)/sizeof(arr[0]);
	int k = 4;
	int pairsCount = noOfPairs(arr, n, k);
	cout << "Total Pairs :\t" << pairsCount << endl;
	return 0;
}
