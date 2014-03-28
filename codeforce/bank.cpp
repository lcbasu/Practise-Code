#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctype.h>
#include <math.h>
#include <limits>	// numeric_limits<int>::max() similarly for other

using namespace std;

int main()
{
	int n;
	cin >> n;
	if(n>=0)
		cout << n << endl;
	else
	{
		n = (-1) * n;
		int unitDig = n%10;
		long long int d1 = n/10;
		long long int d2 = ((n/100)*10) + unitDig;
		if(d1 > d2)
			cout << d2*(-1) << endl;
		else
			cout << d1*(-1) << endl;
	}
	return 0;
}