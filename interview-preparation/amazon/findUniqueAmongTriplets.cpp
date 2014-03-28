#include <iostream>

using namespace std;

int findUnique(int arr[], int n)
{
	int ones = 0;
	int twos = 0;
	int notThrees = 0;
	int x;
	for(int i = 0; i < n; i++)
	{
		x = arr[i];
		twos = twos | (ones&x);
		ones = ones^x;
		notThrees = ~(ones&twos);
		ones = ones & notThrees;
		twos = twos & notThrees;
	}
	return ones;
}

int main()
{
	int arr[] = {11, 11, 11, 3, 3, 3, 77};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << findUnique(arr, n) << endl;
	return 0;
}
