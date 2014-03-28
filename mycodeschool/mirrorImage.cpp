#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, m;
		cin >> n >> m;
		string *arr = new string[n];

		for (int i = 0; i < n; ++i)
		{
			cin >> arr[i];
		}

		char V_H;
		cin >> V_H;
		if(V_H == 'V')
		{
			for (int i = 0; i < n; i++)
			{
				for(int j = m-1; j >= 0; j--)
				{
					cout << arr[i][j];
				}
				cout << endl;
			}
		}
		else if(V_H == 'H')
		{
			for (int i = n-1; i >= 0; i--)
			{
				for(int j = 0; j < m; j++)
				{
					cout << arr[i][j];
				}
				cout << endl;
			}			
		}
		cout << endl;
	}
	return 0;
}