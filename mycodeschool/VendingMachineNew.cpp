#include <iostream>

using namespace std;

/*
using recursion to solve it as the coin change problem is same as this one 
*/

int coinChange(int coinDesig[], int n, int p)
{
	if(p==0)
		return 1;
	if(p<0)
		return 0;
	if(p>0 && n<=0)
		return 0;
	return coinChange(coinDesig, n-1, p) + coinChange(coinDesig, n, p - coinDesig[n-1]);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, p;
		cin >> n >> p;
		int *coinDesig = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> coinDesig[i];
		}
		if(coinChange(coinDesig, n, p) != 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}