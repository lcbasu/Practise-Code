#include <iostream>
#include <string>

using namespace std;

int main()
{
	struct test
	{
		int sNo;
		string name;
	}t[2];

	t[0].sNo = 1;
	t[0].name = "Lokesh";
	t[1].sNo = 2;
	t[1].name = "Mahesh";
	cout << t[0].sNo << endl;
	cout << t[0].name << endl;
	cout << t[1].sNo << endl;
	cout << t[1].name << endl;
	return 0;	
}