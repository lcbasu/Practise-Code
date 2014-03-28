#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

#define lli long long int

void applyOp1(int *arr, int N)
{
	for (int i = 0; i < N; ++i)
	{
		arr[i] = arr[i] + 1;
	}
}

int main()
{
	lli N, X;
	cin >> N;
	lli *arr = new lli[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> arr[i];
	}
	cin >> X;
	sort(arr, arr+N);
	lli zero = 0;
	lli op1 = max(zero, -arr[X-1]);
	lli cost1 = op1*X;
	lli op2 = 0;
	for (int i = 0; i <= X-2; ++i)
	{
		op2 = op2 + max(zero, -(arr[i]+op1));
	}
	lli cost2 = op2;

	printf("%lld\n", (cost1+cost2));
	
	return 0;
}