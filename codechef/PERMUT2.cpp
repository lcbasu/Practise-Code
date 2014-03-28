#include <iostream>

using namespace std;

int main()
{
	int n;
	cin >> n;
	while(n != 0)
	{
		int *permutation = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> permutation[i];
		}
		bool ambiguous = true;
		for (int i = 0; i < n; ++i)
		{
			int tmpIndex = permutation[i]-1;
			if(permutation[tmpIndex] != i+1)
			{
				ambiguous = false;
				break;
			}
		}
		if(ambiguous)
			cout << "ambiguous" << endl;
		else
			cout << "not ambiguous" << endl;
		cin >> n;
	}
	return 0;
}