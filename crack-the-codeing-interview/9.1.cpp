#include <iostream>

using namespace std;

int stairs(int n)
{
	if(n == 0)
		return 1;
	if(n < 0)
		return 0;
	return stairs(n-1) + stairs(n-2) + stairs(n-3);
}

int main()
{
	int n;
	cout << "N : ";
	cin >> n;
	cout << "Total ways : " << stairs(n) << endl;
	return 0;
}