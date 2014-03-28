#include <iostream>
#include <algorithm>
#include <cstdio>

using namespace std;

int maxDivide(int number, int n)
{
	while(number%n == 0)
	{
		number = number/n;
	}
	return number;
}

bool isUgly(int number)
{
	number = maxDivide(number, 2);
	number = maxDivide(number, 3);
	number = maxDivide(number, 5);
	if(number == 1)
		return true;
	return false;
}

int uglyNo(int k)
{
	int number = 1;
	while(k)
	{
		if(isUgly(number))
			k--;
		number++;
	}
	return number;
}

int main()
{
	cout << uglyNo(150);
   return 0;
}
