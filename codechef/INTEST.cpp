#include <cstdio>

int main()
{
	int n, k;
	scanf("%d %d", &n, &k);
	int count = 0;
	while(n--)
	{
		int t;
		scanf("%d", &t);
		if(t%k==0)
			count++;
	}
	printf("%d\n", count);
	return 0;
}