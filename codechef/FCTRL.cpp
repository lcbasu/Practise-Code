#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int d = 5;
		int count = 0;
		while(n/d > 0)
		{
			count += n/d;
			d = d*5;
		}
		cout << count << endl;
	}
	return 0;
}