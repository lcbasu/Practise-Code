#include <iostream>
using namespace std;

int fibonacci(int n)
{
	if(n==0)
		return 0;
	else
	{
		int prev = 0;
		int curr = 1;
		int new_val;
		new_val = prev + curr;
		for (int i = 2; i <= n; i++)
		{
			prev = curr;
			curr = new_val;
			new_val = prev + curr;
		}
		return new_val;
	}	
}

int main()
{
	cout << fibonacci(3) << endl;
	return 0;
}