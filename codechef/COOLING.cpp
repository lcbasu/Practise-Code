#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

bool descending(int a, int b)
{
	return a>b;
}

int totalPossibility(int pies[], int racks[], int n)
{
	sort(pies, pies + n, descending);
	sort(racks, racks + n, descending);
	int count = 0;
	int piesPtr;
	int racksPtr = 0;
	for(int piesPtr = 0; piesPtr < n; piesPtr++)
	{
		if(pies[piesPtr] <= racks[racksPtr])
		{
			count++;
			racksPtr++;
		}
	}
	return count;
}

int main()
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		int n;
		scanf("%d", &n);
		int *pies = new int[n];
		int *racks = new int[n];
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &pies[i]);
		}
		for(int i = 0; i < n; i++)
		{
			scanf("%d", &racks[i]);
		}
		int total = totalPossibility(pies, racks, n);
		printf("%d\n", total);
	}
	return 0;
}