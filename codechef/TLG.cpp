#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int L = 0;
	int W = 0;
	int S = 0;
	int T = 0;
	while(N--)
	{
		int s, t;

		cin >> s >> t;

		S = S + s;
		T = T + t;

		int diff = S - T;
		
		if(diff == 0)
			continue;

		if(diff > 0)
		{
			if(diff > L)
			{
				L = diff;
				W = 1;
			}
		}
		else
		{
			diff = diff * (-1);
			if(diff > L)
			{
				L = diff;
				W = 2;
			}
		}
	}
	cout << W << " " << L << endl;
	return 0;
}