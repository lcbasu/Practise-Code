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
		bool prime = true;
		if(n <= 1)
			prime = false;
		int sqRoot = sqrt(n);
		for (int i = 2; i <= sqRoot; ++i)
		{
			if(n%i == 0)
			{
				prime = false;
				break;
			}
		}
		if(prime)
			cout << "PRIME" << endl;
		else
			cout << "NOT PRIME" << endl;
	}
	return 0;
}
