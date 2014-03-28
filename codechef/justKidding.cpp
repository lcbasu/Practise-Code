#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cstdio>

using namespace std;

int main()
{
	int a = 9;
	int b = 6;
	cout << "a : " << a << " b : " << b << endl;
	a = a^b;
	b = a^b;
	a = a^b;
	cout << "a : " << a << " b : " << b << endl;
    return 0;
}
