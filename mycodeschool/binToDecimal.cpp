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
		int sum = 0;
		int i = 0;
		while(n>0)
		{
			int digit = n%10;
			sum = sum + (digit*pow(2.0, i));
			i++;
			n = n/10;
		}
		cout << sum << endl;
	}
	return 0;
}