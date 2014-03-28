/*

References 

https://code.google.com/p/kooj/source/browse/SPOJ/300/346.+Bytelandian+gold+coins.cpp?r=e587d6e7782b8f83ba47c95799b6c598303ed5b2

http://nishantarora.in/bytelandian-gold-coins.naml



*/


#include <iostream>
#include <algorithm>
#include <map>
#include <cstdio>

#define lli long long int

using namespace std;

map<lli, lli> cache;

lli coins(lli n)
{
	if(n<=0)
		return 0;
	if(cache.count(n))
		return cache[n];
	cache[n] = max(n, coins(n/2)+coins(n/3)+coins(n/4));
	return cache[n];
}

int main()
{
	lli n;
	while(scanf("%lld", &n) != EOF)
	{		
		printf("%lld\n", coins(n));
	}
	return 0;
}
