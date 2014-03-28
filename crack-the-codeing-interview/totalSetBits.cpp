#include <iostream>

using namespace std;

int getTotalNoOfSetBits(int n)
{
	int i = 0, count = 0;
	while(n != 0)
	{
		if((n & (1 << i)) != 0)
		{
			count++;
			n = n ^ (1 << i);	//xor only if the ith bit is 1
		}
		i++;
	}
	return count;
}

int main()
{
	cout << getTotalNoOfSetBits(16) << endl;;
	return 0;
}