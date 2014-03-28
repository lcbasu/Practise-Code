#include <iostream>

using namespace std;

int getBit(int num, int i)
{
	return num & (1 << i);
}

int setBit(int num, int i)
{
	num = num | (1 << i);
	return num;
}

int clearBit(int *num, int i)
{
	*num = *num & ~(1 << i);
	return *num;
}

int flipBit(int *num, int i)
{
	*num = *num ^ (1 << i);
	return *num;
}

int main()
{
	int a = 4;
	cout << getBit(a, 2) << endl;
	cout << setBit(a, 3) << endl;
	cout << clearBit(&a, 3) << endl;
	cout << flipBit(&a, 3) << endl;
	cout << flipBit(&a, 3) << endl;
	return 0;
}
