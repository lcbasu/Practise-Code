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

class DeerInZooDivTwo
{
public:
    vector <int> getminmax(int N, int K)
    {
        vector<int> result;
        int min, max;
        int total = 2*N;
        int remaining = total-K;
        max = remaining/2;
        if(remaining <= N)
        	min = 0;
        else
        	min = remaining - N;
        result.push_back(min);
        result.push_back(max);
        return result;
    }
};
