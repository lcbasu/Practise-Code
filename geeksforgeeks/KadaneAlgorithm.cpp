#include <iostream>
#include <algorithm>

using namespace std;


//all negative case is covered in v2
int kadaneAlgo(int arr[], int n)
{
	if(n<=0)
		return -1;
	int maxEndingHere = 0;
	int maxSoFar = 0;
	for (int i = 0; i < n; ++i)
	{
		maxEndingHere = maxEndingHere + arr[i];
		if(maxEndingHere < 0)
			maxEndingHere = 0;
		else if(maxEndingHere > maxSoFar)
			maxSoFar = maxEndingHere;
	}
	return maxSoFar;
}

int kadaneAlgoV2(int arr[], int n)
{
	if(n<=0)
		return -1;
	int maxEndingHere = arr[0];
	int maxSoFar = arr[0];
	for (int i = 0; i < n; ++i)
	{
		maxEndingHere = max(arr[i], maxEndingHere + arr[i]);
		maxSoFar = max(maxSoFar, maxEndingHere);
	}
	return maxSoFar;
}

int main()
{
	int arr[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	cout << kadaneAlgo(arr, 8) << endl;

	int arrV2[] = {-2, -3, -4, -1, -2, -1, -5, -3};
	cout << kadaneAlgoV2(arrV2, 8) << endl;
	return 0;
}