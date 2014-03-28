#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n, k;
		cin >> n >> k;
		vector<int> seq;
		for (int i = 0; i < n; ++i)
		{
			int tmp;
			cin >> tmp;
			seq.push_back(tmp);
		}
		sort(seq.begin(), seq.end());

		cout << seq[k-1] << endl;
	}
	return 0;
}
