#include <iostream>

using namespace std;

int main()
{
	int n,t;
	cin >> n >> t;
	
	char c[n+1];
	cin >> c;

	for (int i = 1; i <= t; i++)
	{
		int j = 0;
		while(j<n)
		{
			if((c[j] == 'B') && (c[j+1] == 'G'))
			{
				char temp = c[j];
				c[j] = c[j+1];
				c[j+1] = temp;
				j = j+2;
				continue;
			}
			else
				j = j+1;
		}
	}

	cout << c << endl;

	return 0;
}