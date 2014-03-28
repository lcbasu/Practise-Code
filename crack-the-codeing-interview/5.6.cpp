#include <iostream>

using namespace std;

int flipOddEven(int num)
{
	int left = (num & 0xAAAAAAAA) >> 1;
	int right = (num & 0x55555555) << 1;
	return (left | right);
}

int main()
{
	int num;
	cout << "Num : ";
	cin >> num;
	cout << flipOddEven(num) << endl;
	return 0;
}