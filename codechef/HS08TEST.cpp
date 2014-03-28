#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int X;
	float AB;
	cin >> X >> AB;
	if(X%5==0 && (X+0.50)<=AB)
	{
		cout << fixed << setprecision(2) << (AB-0.50-X) << endl;
	}
	else
	{
		cout << fixed << setprecision(2) << AB << endl;
	}
	return 0;
}