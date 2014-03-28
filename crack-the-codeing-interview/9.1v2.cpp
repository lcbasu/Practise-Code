#include <iostream>

using namespace std;

int *cache;

int stairs(int n)
{
	if(n < 0)
		return 0;
	if(cache[n] > 0)
		return cache[n];
	cache[n] = stairs(n-1) + stairs(n-2) + stairs(n-3);
	return cache[n];
}

int main()
{
	int n;
	cout << "N : ";
	cin >> n;
	cache = new int[n+1];
	for (int i = 0; i < n+1; ++i)
	{
		cache[i] = 0;
	}
	cache[0] = 1;
	cout << "Total ways : " << stairs(n) << endl;
	return 0;
}