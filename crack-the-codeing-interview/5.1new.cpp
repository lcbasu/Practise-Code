#include <iostream>

using namespace std;

int insertInto(int n, int m, int i, int j)
{
	int maskMSB = ~(1 << (j+1)) - 1;
	int maskLSB = (1 << i) - 1;
	n = ((n & maskMSB) | (n & maskLSB));
	m = m << i;
	return n | m;
}


int main()
{
	cout << insertInto(1024, 19, 2, 6) << endl;
	return 0;
}