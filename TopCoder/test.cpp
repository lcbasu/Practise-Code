#include <iostream>
#include <limits>
#include <sstream>

using namespace std;

int main()
{

	string num = "1 2 3 4";

	stringstream ss;
	ss << num;

	int a, b, c, d;

	ss >> a >> b >> c >> d;

	cout << a+b+c+d*2 << endl;;

	return 0;
}

