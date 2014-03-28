#include <iostream>

using namespace std;

bool isValid(int arr[], int n, int pos, int currentSum, int price)
{
	if(n == pos)
	{
		if(currentSum == price)
			return true;
		return false;
	}
	bool resultWithCurrentCoin = isValid(arr, n, pos+1, currentSum + arr[pos], price);
	bool resultWithoutCurrentCoin = isValid(arr, n, pos+1, currentSum, price);
	return (resultWithCurrentCoin || resultWithoutCurrentCoin);
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
		if(isValid(coinDesig, n, 0, 0, p))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;


		delete[] coinDesig;
	}
	return 0;
}