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
		int i = 0;
		while(n >= pow(2.0,i+1))
		{
			i++;
		}
		for (int j = i; j >= 0; j--)
		{
			if(pow(2.0,j) <= n && n != 0)
			{
				cout << "1";
				n = n - pow(2.0,j);
			}
			else
			{
				cout << "0";
			}
		}
		cout << endl;
	}
	return 0;
}