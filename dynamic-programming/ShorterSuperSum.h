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

class ShorterSuperSum
{
public:
    int calculate(int k, int n)
    {
    	int SS[100][100];
    	for (int i = 0; i <= n; ++i)
    	{
    		SS[0][i] = i;
    	}
    }

};