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

class SkiResortsEasy
{
public:
    int minCost(vector <int> altitude)
    {
        int totalCost = 0;
        for (int i = 1; i < altitude.size(); ++i)
        {
        	if(altitude[i-1] < altitude[i])
        	{
        		totalCost = totalCost + (altitude[i] - altitude[i-1]);
        		altitude[i] = altitude[i-1];
        	}
        }
        return totalCost;
    }
};
