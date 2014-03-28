#include <iostream>
#include <cstdio>

using namespace std;

int *particleCount;


void output(int k)
{
	for(int i = 0; i < k; i++)
		printf("%d ", particleCount[i]);
	printf("\n");
}

int main()
{
	int a,n,k;
	scanf("%d %d %d", &a, &n, &k);
	particleCount = new int[k];
	for(int i = 0; i < k; i++)
		particleCount[i] = 0;

	int i = 0;
	while(a)
	{
		particleCount[i] = a%(n+1);
		a = a/(n+1);
		i++;
		if(i >= k)
			break;
	}
	output(k);
	return 0;
}