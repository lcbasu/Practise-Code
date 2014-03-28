#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
	int N, Q;
	scanf("%d %d", &N, &Q);
	int *A = new int[N];
	for (int i = 0; i < N; ++i)
	{
		scanf("%d", &A[i]);
	}
	while(Q--)
	{
		int L, R, K;
		scanf("%d %d %d", &L, &R, &K);
		int count = 0;
		for (int i = L-1; i < R; i++)
		{
			if(A[i]%K == 0)
				count++;
		}
		printf("%d\n", count);
	}
	return 0;
}