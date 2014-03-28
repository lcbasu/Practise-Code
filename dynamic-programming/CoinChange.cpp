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

// C(S) = C(S-Vi) + 1 Vi <= S
int coinChange(int);
int coinChangeAux(int, int*, int*);


int coinChange(int S)
{
	int minCoin[S+1];

	for (int i = 0; i < S+1; ++i)
	{
		minCoin[i] = numeric_limits<int>::max();
	}

	minCoin[0] = 0;

	int coinValue[] = {1,2,3};

	for (int i = 1; i <= S; ++i)
	{
		for(int j = 0; j < 3; j++)
		{
			if(coinValue[j] <= i && minCoin[i] > minCoin[i-coinValue[j]] +1)
				minCoin[i] = minCoin[i-coinValue[j]] +1;
		}
	}
	return minCoin[S];
}


int main()
{
	cout << coinChange(11) << endl;
	return 0;
}
