#include <iostream>
#include <cmath>

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
		int sum = 0;
		for (int i = 1; i <= sqRoot; i++)
		{
			if(n%i == 0)
			{
				sum = sum + i;
				if(i != sqRoot)
				{
					sum = sum + (n/i);
				}
			}
		}
		cout << sum << endl;
	}
	return 0;
}