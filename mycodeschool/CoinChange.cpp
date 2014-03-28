#include <iostream>
#include <limits>	// numeric_limits<int>::max() similarly for other

using namespace std;

void coinChange(int *minChange, int *coinDesg, int n, int s)
{
	for(int amount = 1; amount <= s; amount++)
	{
		int min = numeric_limits<int>::max();
		bool noChange = true;
		for(int coin = 0; coin < n; coin++)
		{
			if(coinDesg[coin] <= amount)
			{
				if((1+minChange[amount-coinDesg[coin]]) < min && minChange[amount-coinDesg[coin]] >= 0)
				{
					min = 1+minChange[amount-coinDesg[coin]];
					noChange = false;
				}
			}
		}
		if(!noChange)
			minChange[amount] = min;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *coinDesg = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> coinDesg[i];
		}
		int s;
		cin >> s;
		int *minChange = new int[s+1];
		minChange[0] = 0;
		for (int i = 1; i < s+1; ++i)
		{
			minChange[i] = -1;
		}
		coinChange(minChange, coinDesg, n, s);
		cout << minChange[s] << endl;
	}
	return 0;
}