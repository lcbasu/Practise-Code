#include <iostream>

using namespace std;

int main()
{
	int a = 10;
	int b = 12;
	int max = a^((a^b)& -(a<b));
	int min = b^((a^b)& -(a<b));

	cout << "Max : " << max << "\nMin : " << min << endl;
	return 0;
}