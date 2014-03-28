#include <iostream>

using namespace std;

void error()
{
	cout << "Error Value!\n";
}

int getNext(int n)
{
	if(n <= 0)
	{
		error();
		return -1;
	}
	int c = n;
	int c0 = 0;
	int c1 = 0;
	while((c & 1 == 0) && (c != 0))
	{
		c0++;
		c = c >> 1;
	}
	while(c & 1 == 1)
	{
		c1++;
		c = c >> 1;
	}
	int p = c0 + c1;
	if(p == 31 || p == 0)
	{
		error();
		return -1;
	}

	n = n | (1 << p);	//flipping non trailing zero
	n = n & (~((1 << p) - 1));
	n = n | ((1 << (c1 - 1)) - 1);
	return n;
}

int main()
{
	cout << getNext(18) << endl;
	return 0;
}