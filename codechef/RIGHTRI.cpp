#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

int main()
{
	int N;
	scanf("%d", &N);
	int count = 0;
	while(N--)
	{
		int arr[2][3];
		for (int i = 0; i < 3; ++i)
		{
			scanf("%d %d", &arr[0][i], &arr[1][i]);
		}
		int d1 = pow((arr[0][0] - arr[0][1]), 2) + pow((arr[1][0] - arr[1][1]), 2);
		int d2 = pow((arr[0][1] - arr[0][2]), 2) + pow((arr[1][1] - arr[1][2]), 2);
		int d3 = pow((arr[0][2] - arr[0][0]), 2) + pow((arr[1][2] - arr[1][0]), 2);
		if(((d1+d2) == d3) || ((d3+d1) == d2) || ((d2+d3) == d1))
			count++;
	}
	printf("%d\n", count);
	return 0;
}