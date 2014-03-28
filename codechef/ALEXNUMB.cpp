#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		long long int n;	//very important part to think about taking n as long long int
		scanf("%lld", &n);
		int count = n;
		while(count--)
		{
			int a;
			scanf("%d", &a);
		}
		if(n < 2)
			printf("%d\n", 0);
		else
			printf("%lld\n", (n*(n-1))/2);
	}
	return 0;
}
