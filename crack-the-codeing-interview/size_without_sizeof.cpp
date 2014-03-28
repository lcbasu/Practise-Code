/*
Declare 2 pointer variable of the same type and assign the address of the variable to them and then increment one of them.

Find the difference between the above 2 pointers using a type cast. This will be the size of the variable.
*/


#include <iostream>


using namespace std;

int main()
{
	double i;
	double *p,*q;

	p = &i;
	q=p;
	p++;

	cout << (int)p - (int)q << endl;
    return 0;
}
