#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	char c[n+1];
	cin >> c;
	int count = 0;
	for (int i = 0; i < n-1; i++)
	{
		if((c[i] == 'R' && c[i+1] == 'R') || (c[i] == 'G' && c[i+1] == 'G') || (c[i] == 'B' && c[i+1] == 'B'))
			count++;
	}
	cout << count << endl;
	return 0;
}