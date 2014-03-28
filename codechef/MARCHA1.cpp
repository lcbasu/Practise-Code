#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPossible(int arr[], int n, int m)
{
	if(m>20*1000 || m < 0)	//since only 20 notes can be accomodated with a max value of 1000
		return false;
	if(m == 0)
		return true;

	bool result = false;
	for (int i = 1; i < pow(2, n); i++)	// i = 1 because we nned to select at least one note to make the sum, we exclude the 2^n point because
	{									// we only need to move form 1 to 2^n - 1 as 2^n = 1000...0 1 followed by n zeros that means n+1
		int sum  = 0;					// element but we only want n elemets 
		for(int j = 0; j < n; j++)
		{
			if((i & 1<<j ) != 0)
				sum = sum + arr[j];
		}
		if(sum == m)
		{
			result = true;
			break;
		}
	}
	return result;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n, m;
		scanf("%d %d", &n, &m);
		int *arr = new int[n];
		for (int i = 0; i < n; ++i)
		{
			scanf("%d", &arr[i]);
		}
		if(isPossible(arr, n, m))
			cout << "Yes" << endl;
		else
			cout << "No" << endl;
	}
	return 0;
}