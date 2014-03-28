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
		int digit = 2;
		int digitCount = 0;
		bool prevDigitPresent = false;
		while(n%2 == 0)
		{
			prevDigitPresent = true;			
			digitCount++;
			n = n/2;
		}
		if(digitCount > 0)
			cout << digit << "^" << digitCount;
		int sqRoot = sqrt(n);
		for(digit = 3;digit <= sqRoot && n > 0; digit = digit + 2)
		{
			digitCount = 0;
			while(n%digit == 0)
			{
				digitCount++;
				n = n/digit;
			}
			if(digitCount > 0 && prevDigitPresent)
			{
				cout << "*" << digit << "^" << digitCount;
			}
			else if(digitCount > 0 && !prevDigitPresent)
			{
				cout << digit << "^" << digitCount;
				prevDigitPresent = true;
			}
			else
				continue;			
		}
		if(n>2 && prevDigitPresent)
			cout << "*" << n << "^1" << endl;
		else if(n>2 && !prevDigitPresent)
			cout << n << "^1" << endl;
		else
			cout << endl;
	}
	return 0;
}