#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n];

	cin >> a[0];

	int min_val = a[0];
	int min_index = 0;

	for (int i = 1; i < n; ++i)
	{
		cin >> a[i];
		if(a[i] < min_val)
		{
			min_val = a[i];
			min_index = i;
		}
	}

	cout << min_index << endl;


	return 0;
}