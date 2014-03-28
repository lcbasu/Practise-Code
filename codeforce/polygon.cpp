#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	for(int i = 1; i<=t; i++)
	{
		double a;
		cin >> a;

		bool possible = false;

		for(int n=3; n<=180; n++)
		{
			double int_angle = 180*(n-2)/n;
			if(int_angle == a)
			{
				possible = true;
				break;
			}
		}

		if(possible)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}