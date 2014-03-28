#include <iostream>

using namespace std;

int main()
{
	int num = 32;
	if(num && !(num & (num-1)))
		cout << num << " is pow of 2.\n";
	else
		cout << num << " isn't a pow of 2.\n";
	return 0;
}