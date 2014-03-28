#include <iostream>
#include <math.h>

#define log2(x) (log10(x)/log10(2))

using namespace std;

int main()
{
	int n;
	cin >> n;

	int totalTestCases[n];

	for (int i = 0; i < n; i++)
	{
		cin >> totalTestCases[i];
	}

	cout << "\n";

	for (int j = 0; j < n; j++)
	{
		cout << int(pow(2, floor((log2(totalTestCases[j]))))) << "\n";
	}
	cout << endl;
	return 0;
}
