#include <iostream>

using namespace std;

bool isLucky(int n)
{
	while(n>0)
	{
		int unit = n%10;
		if(unit % 2 == 0)
		{
			return false;
		}
		n = n/10;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		int num = 0;
		while(true)
		{
			if(isLucky(num))
				k--;
			if(k<0)
			{
				cout << num << endl;
				break;
			}
			num++;
		}
	}
	return 0;
}