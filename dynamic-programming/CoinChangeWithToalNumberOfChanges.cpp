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

int coinChange(int V[], int S, int m)
{
	if(S == 0)
		return 1;
	if(S < 0)
		return 0;
	if(S >= 1 && m <= 0)
		return 0;
	return (coinChange(V, S, m-1) + coinChange(V, (S-V[m-1]), m));
}


int main()
{
	int V[] = {1,2,3};
	cout << coinChange(V, 4, sizeof(V)/sizeof(V[0])) << endl;
	return 0;
}