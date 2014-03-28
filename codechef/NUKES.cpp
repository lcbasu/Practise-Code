#include <iostream>
#include <cstdio>

using namespace std;

int *particleCount;

void bombard(int *a, int n)
{
	if(*a > n)
	{
		particleCount[0] = n+1;
		*a = *a - (n+1);
	}
	else
	{
		particleCount[0] = *a;
		*a = 0;
	}
}

void balance(int n, int k)
{
	if(particleCount[0]>n)
	{
		for(int i = 0; i < k; i++)
		{
			if(particleCount[i] > n)
			{
				particleCount[i] = 0;
				if(i < (k-1))	//since the last particle is to be lost
					particleCount[i+1] += 1;
			}
			else
				break;
		}
	}
}

void reaction(int *a, int n, int k)
{
	bombard(a, n);
	balance(n, k);
}

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
	while(a)
	{
		reaction(&a, n, k);
	}
	output(k);
	return 0;
}