#include <iostream>
#include <cstdio>

#define lld long long int

using namespace std;

int main()
{
	lld t;
	scanf("%lld", &t);
	while(t--)
	{
		lld n, k;
		scanf("%lld %lld", &n, &k);
		lld ans = 1;
		n--;
		k--;
		if(k > n/2)
			k = n - k;
		for(lld i = 1; i <= k; i++)
		{
			ans = ans*(n+1-i)/i;
		}
		printf("%lld\n", ans);
	}
	return 0;
}