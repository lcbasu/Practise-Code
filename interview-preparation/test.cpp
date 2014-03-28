#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	stringstream ss;
	string stng;
	int num = 123;
	ss <<  num;
	ss >> stng;
	cout << stng.size() << endl;
	return 0;
}
