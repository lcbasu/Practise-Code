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

using namespace std;

class EllipseCoverage
{
public:
    int calculateCoverage(int x1, int y1, int x2, int y2, int d)
    {
    	int count = 0;
        for(int x = -200; x <= 200; x++)
        {
        	for(int y = -200; y <= 200; y++)
        	{
        		double d1 = sqrt((pow((x-x1), 2) + pow((y-y1), 2)));
        		double d2 = sqrt((pow((x-x2), 2) + pow((y-y2), 2)));
        		if(static_cast<int>(d1+d2) < d)
        			count++;
        	}
        }
        return count;
    }
};
