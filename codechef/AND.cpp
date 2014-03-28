#include <iostream>

using namespace std;

int main()
{
	int N;
	cin >> N;
	int *A = new int[N];
	for (int i = 0; i < N; ++i)
	{
		cin >> A[i];
	}
	long long int sum = 0;
	for (int j = 1; j < N; j++)
	{
		for(int i = 0; i < j; i++)
		{
			sum += (A[i] & A[j]);
		}
	}
	cout << sum << endl;
	return 0;
}