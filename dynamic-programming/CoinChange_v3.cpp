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

void coinChange(int S)
{
	int minNoOfCoins[S+1];
	for (int i = 0; i < S+1; ++i)
	{
		minNoOfCoins[i] = INFNTY;
	}
	minNoOfCoins[0] = 0;
	int coinValue[] = {1,2,3};
	for (int presentSum = 1; presentSum <= S; presentSum++)
	{
		for(int j = 0; j < 3; j++)
		{
			if(coinValue[j] <= presentSum && minNoOfCoins[presentSum] > minNoOfCoins[presentSum- coinValue[j]]+1)
				minNoOfCoins[presentSum] = minNoOfCoins[presentSum - coinValue[j]]+1;
		}
	}

	cout << minNoOfCoins[S] << endl;
}


int main()
{
	coinChange(0);
	coinChange(5);
	coinChange(11);
	coinChange(12);
	return 0;
}
