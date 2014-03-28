#include <iostream>

#define LL long long int

using namespace std;

LL modularExp(int x, int n, int M)
{
	LL half;
	if(n==0)
		return 1;
	else if(n%2==0)
	{
		half = modularExp(x, n/2, M);
		return (half*half)%M;
	}
	else
		return ((x%M)*modularExp(x, n-1, M))%M;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int X, n, M;
		cin >> X >> n >> M;
		cout << modularExp(X, n, M) << endl;
	}
	return 0;
}