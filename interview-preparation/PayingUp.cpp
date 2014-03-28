#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	int t, n, m, result, sum, flag;
	cin >> t ;
	for (int k = 0; k < t; k++)
	{
		cin >> n >> m;
		flag = -1;
		int *numbers = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> numbers[i];
		}
		result = pow(2,n);
		for (int i = 1; i < result; i++)
		{
			sum = 0;
			for(int j = 0; j < n; j++)
			{
				if(i & (1<<j) > 0)
					sum = sum + numbers[j];
			}
			if(sum == m)
			{
				cout << "YES" << endl;
				flag = 1;
				break;
			}
			else
				flag = 0;
		}
		if(flag == 0)
			cout << "NO" << endl;
	}
	return 0;
}