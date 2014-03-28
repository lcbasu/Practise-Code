#include <iostream>
#include <vector>
#include <stack>
#include <ctime>

using namespace std;

int main()
{
	time_t timer;
	time(&timer);

	cout << timer << endl;

	time(&timer);

	cout << timer << endl;	
    return 0;
}
