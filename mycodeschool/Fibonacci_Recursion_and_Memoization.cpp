#include <iostream>

using namespace std;

int memory[1000];

int recrsiveFib(int n)
{
	if(n<=1)
		return n;
	return recrsiveFib(n-1)+recrsiveFib(n-2);
}

int memoizationFib(int n)
{
	if(memory[n] >= 0)
		return memory[n];
	memory[n] = memoizationFib(n-1) + memoizationFib(n-2);
	return memory[n];
}

int main()
{
	for (int i = 0; i < 1000; ++i)
	{
		memory[i] = -1;
	}
	memory[0] = 0;
	memory[1] = 1;
	cout << "Fibonacci with recursion with memoization : " << memoizationFib(40) << endl;
	cout << "Fibonacci with recursion without memoization : " << recrsiveFib(40) << endl;


	return 0;
}