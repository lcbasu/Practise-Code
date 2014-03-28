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

#define INFNTY numeric_limits<int>::max()

int coinChange(int S)
{
	int minNoOfCoins[S+1];
	for (int i = 0; i < S+1; ++i)
	{
		minNoOfCoins[i] = INFNTY;
	}
	minNoOfCoins[0] = 0;
	int V[] = {1,2,3};

	for (int i = 1; i <= S; ++i)
	{
		for(int j = 0; j < 3; j++)
		{
			if(V[j] <= i && minNoOfCoins[i] > minNoOfCoins[i-V[j]]+1)
				minNoOfCoins[i] = minNoOfCoins[i-V[j]]+1;
		}
	}

	return minNoOfCoins[S];
}

int main()
{
	cout << coinChange(112) << endl;
	return 0;
}
