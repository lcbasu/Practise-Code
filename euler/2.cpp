#include <iostream>
using namespace std;

long fibonacciSum();

int main()
{
	cout << "Sum : " << fibonacciSum() << endl;
	return 0;
}

long fibonacciSum()
{
	long f0 = 0;
	long f1 = 1;
	long fib=0, sum=0;
	while(fib<4000000)
	{
		fib = f0+f1;
		f0 = f1;
		f1 = fib;
		if(fib%2==0)
			sum += fib;
	}
	return sum;
}