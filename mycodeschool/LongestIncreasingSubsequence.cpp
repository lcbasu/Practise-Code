#include <iostream>
#include <limits>	// numeric_limits<int>::max() similarly for other
#define LLI long long int


using namespace std;

LLI lis(int *sequence, LLI n)
{
	int *lisArr = new int[n];
	for (int i = 0; i < n; ++i)
	{
		lisArr[i] = 1;
	}
	for (int i = 0; i < n; ++i)
	{
		int max = 0;
		bool flag = false;
		for(int j = 0; j < i; j++)
		{
			if(sequence[i] > sequence[j] && lisArr[j] > max)
			{
				max = lisArr[j];
				flag = true;
			}
		}
		if(flag)
			lisArr[i] = 1 + max;
	}
	return lisArr[n-1];
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		LLI n;
		cin >> n;
		int *sequence = new int[n];
		for (int i = 0; i < n; ++i)
		{
			cin >> sequence[i];
		}
		cout << lis(sequence, n) << endl;
	}
	return 0;
}