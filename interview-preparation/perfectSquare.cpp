#include <iostream>
#include <cmath>

#define lli long long int

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		lli n;
		cin >> n;
		lli reqNumber = 1;
		int digit = 2;
		int digitCount = 0;
		while(n%2 == 0)
		{
			digitCount++;
			n = n/2;
		}
		if(digitCount%2 != 0)
		{
			reqNumber = reqNumber * digit;
		}			
		lli sqRoot = sqrt(n);
		for(digit = 3; digit <= sqRoot && n > 0; digit = digit + 2)
		{
			digitCount = 0;
			while(n%digit == 0)
			{
				digitCount++;
				n = n/digit;
			}
			if(digitCount%2 != 0)
			{
				reqNumber = reqNumber * digit;	
			}
		}
		if(n>2)
		{
			reqNumber = reqNumber * n;
		}
		cout << reqNumber << endl;
	}
	return 0;
}