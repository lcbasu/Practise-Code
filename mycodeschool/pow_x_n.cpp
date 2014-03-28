#include <iostream>

using namespace std;

#define LL long long int

LL powRecursionSlow(int x, int n)
{
	if(n==0)
		return 1;
	else
		return x*powRecursionSlow(x, n-1);
}

LL powRecursionFast(int x, int n)
{
	if(n==0)
		return 1;
	else if(n%2 == 0)
	{
		LL half = powRecursionFast(x, n/2);
		return half*half;
	}
	else
		return x*powRecursionFast(x, n-1);
}

int main()
{
	cout << "Faster method for power of x to n : " << powRecursionFast(5,100) << endl;
	cout << "Slower method for power of x to n : " << powRecursionSlow(5,100) << endl;
	return 0;
}