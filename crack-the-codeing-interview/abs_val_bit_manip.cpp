#include <iostream>

using namespace std;

int main()
{
	int a = -21232312;
	int mask = a >> (sizeof(int)*8-1);
	unsigned int abs_a = (a+mask)^mask;
	cout << abs_a << endl;
	return 0;
}