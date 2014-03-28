#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int sum = 0;
		int n, m;
		cin >> n >> m;
		int *p = new int[n];
		for (int i = 0; i < n; i++)
		{
			p[i] = 0;
		}

		while(m--)
		{
			int tmp;
			cin >> tmp;
			p[tmp]++;
		}

		for (int i = 0; i < n; ++i)
		{
			vector<int> vol;
			int count;
			cin >> count;
			while(count--)
			{
				int tmp;
				cin >> tmp;
				vol.push_back(tmp);
			}

			sort(vol.begin(), vol.end());

			if(vol.size() <= p[i])
			{
				for (int k = 0; k < vol.size(); k++)
				{
					sum = sum + vol[k];
				}
			}
			else
			{
				for (int k = vol.size()-1; p[i]-- ; k--)
				{
					sum = sum + vol[k];
				}				
			}
		}
		cout << sum << endl;
	}
	return 0;
}