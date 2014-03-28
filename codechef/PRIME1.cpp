#include <iostream>
#include <cstdio>
#include <cmath> 

#define lli long long int

using namespace std;

void initialize(bool *flag, int len)
{
	for (int i = 0; i < len; ++i)
	{
		flag[i] = true;
	}
}

int getNextPrime(bool *flag, lli prime, lli m, lli n)
{
	for(lli i = prime+1; i <= n; i++)
	{
		if(flag[i-m])
			return flag[i-m];
	}
}

void findPrime(bool *flag, int m, int n)
{
	
}

void display(bool *flag, lli m, lli n)
{
	lli len = n - m;
	for (lli i = 0; i < len; ++i)
	{
		if(flag[i])
		{
			printf("%lli\n", (i+m));
		}
	}
}

int main()
{
	int t;
	while(t--)
	{
		lli m, n;
		scanf("%lli %lli", &m, &n);
		int len = n - m;
		bool *flag = new bool[len];
		initialize(flag, len);
	}
	return 0;
}