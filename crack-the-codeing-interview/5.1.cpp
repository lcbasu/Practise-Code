#include <iostream>

using namespace std;

void convert(int n, int m, int i, int j)
{
	int leftMask = (~(0)) << (j+1);
	int rightMask = ((1 << i) -1);
	int mask = leftMask | rightMask;
	int shiftedM = m << i;
	n = n & mask;
	n = n | shiftedM;
	cout << "New : " << n << endl;
}

int main()
{
	int n = 16;
	int m = 3;
	int i = 1;
	int j = 2;
	cout << "Old : " << n << endl;
	convert(n, m, i, j);
	return 0;
}