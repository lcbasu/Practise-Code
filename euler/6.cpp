#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	int n = 100;
	long long int sqSum = n*(n+1)*(2*n+1)/6;
	long long int m = n*(n+1)/2;
	long long int sumSq = pow(m,2);

	cout << sumSq-sqSum << endl;

	return 0;
}