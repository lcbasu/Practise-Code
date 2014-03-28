#include <iostream>
#include <cmath>

using namespace std;

bool isPerfectsquare(int num)
{
	if(num < 0)
		return false;
	int numSqrt = sqrt(num);
	return numSqrt*numSqrt == num;
}

bool isFibonacci(int x)
{
	if(x < 0)
		return false;
	return isPerfectsquare((5*pow(x, 2)) + 4) || isPerfectsquare((5*pow(x, 2)) - 4);
}

int main()
{
	for (int i = 0; i <= 10; ++i)
	{
		if(isFibonacci(i))
			cout << i << "\tis a Fibonacci Number.\n";
		else
			cout << i << "\tisn't a Fibonacci Number.\n";
	}
	return 0;
}
