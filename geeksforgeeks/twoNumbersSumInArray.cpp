#include <iostream>
#include <algorithm>

using namespace std;

bool twoNumbersExists(int arr[], int n, int sum)
{
	sort(arr , arr + n);
	int l = 0;
	int r = n-1;
	while(l < r)
	{
		if(arr[l] + arr[r] == sum)
			return true;
		else if(arr[l] + arr[r] > sum)
			r--;
		else if(arr[l] + arr[r] < sum)
			l++;
	}
	return false;
}

int main()
{
	int arr[] = {-8, 10, 2, 11, 3, 7, 13};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum = 16;
	if(twoNumbersExists(arr, n, sum))
		cout << "True\n";
	else
		cout << "False\n";
	return 0;
}