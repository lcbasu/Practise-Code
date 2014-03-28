#include <iostream>

#define LL long long int

using namespace std;

LL pow(LL n, LL k)
{
	if(k==0)
		return 1;
	else if(k%2 == 0)
	{
		LL tmp = pow(n, k/2);
		return tmp*tmp;
	}
	else
		return n*pow(n, k-1);
}

int main()
{
	LL t;
	cin >> t;
	while(t--)
	{
		LL n;
		cin >> n;
		LL noOfZeros = 0;		
		LL count = 1;
		LL dividor = pow(5, count);
		LL fraction = n/dividor;
		while(fraction > 0)
		{
			noOfZeros += fraction;
			count++;
			dividor = pow(5, count);
			fraction = n/dividor;
		}
		cout << noOfZeros << endl;
	}
	return 0;
}