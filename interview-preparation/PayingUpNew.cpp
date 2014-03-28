#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t, n, m, sum;
	cin >> t;
	while(t--)
	{
		cin >> n >> m;
		int result = pow(2,n);
		int numbers[n];
		int field = 0;
		for (int i = 0; i < n; i++)
		{
			cin >> numbers[i];
		}
		for (int i = 1; i < result; i++)
		{
			sum = 0;
			for (int j = 0; j < n; j++)
			{
				if(i & (1<<j) != 0)
					sum = sum + numbers[j];
			}
			if(sum == m)
			{
				field = 1;
				break;
			}
		}
		if(field == 1)
			cout << "YES";
		else
			cout << "NO";
	}
	return 0;
}