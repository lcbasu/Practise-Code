#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		double sqRoot = sqrt(n);
		vector<int> factors;
		for (int i = 1; i <= sqRoot; i++)
		{
			if(n%i == 0)
			{
				factors.push_back(i);
				if(i != sqRoot)
				{
					factors.push_back(n/i);
				}
			}
		}
		sort(factors.begin(), factors.end());
		cout << factors[0];
		for (int i = 1; i < factors.size(); ++i)
		{
			cout << " " << factors[i];
		}
		cout << endl;
	}
	return 0;
}