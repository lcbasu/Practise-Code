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

class BettingMoney
{
public:
    int moneyMade(vector <int> amounts, vector <int> centsPerDollar, int finalResult)
    {
        int totalSum = 0;
        for (int i = 0; i < amounts.size(); ++i)
        {
        	if(i != finalResult)
        		totalSum += amounts[i];
        }
        return (totalSum*100-(centsPerDollar[finalResult]*amounts[finalResult]));
    }
};
