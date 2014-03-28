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

int coinChange(int V[], int S, int n)
{
	int table[S+1][n];
	for (int i = 0; i < n; ++i)
	{
		table[0][i] = 0;
	}

	for (int i = 1; i <= S; ++i)
	{
		for(int j = 0; j < n; j++)
		{
			
		}
	}

	return table[S][n-1];
}

int main()
{
	return 0;
}