#include <iostream>

using namespace std;

int main()
{
	int a=0,b=0;
	int equ = 0;
	for(a=3; a < 500; a++)
	{
		for(b=4; b<(500-(a/2)) && b > a; b++)
		{
			equ = 2*(1000*(a+b) - (a*b));
			if(equ == 1000*1000)
				break;
		}
		if(equ == 1000*1000)
			break;
	}

	cout << a*b*(1000-(a+b)) << endl;

	return 0;
}