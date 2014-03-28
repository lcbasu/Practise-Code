#include <iostream>
#include "BigIntegerLibrary.hh"

using namespace std;

class Fact
{
public:
	Fact(){}
	int factorial(int);
};

int Fact::factorial(int n)
{
	if(n==1 || n==0)
		return 1;
	else
		return n*factorial(n-1);
}

int main()
{
	Fact obj;
	long long int f = obj.factorial(10);
	long long int sum = 0;
	int d = 0;
	while(f>0)
	{
		d = f%10;
		sum += d;
		f=f/10;
	}
	cout << sum << endl;
	return 0;
}