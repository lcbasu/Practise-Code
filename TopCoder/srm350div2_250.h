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

class DistanceBetweenStrings
{
public:
    int getDistance(string a, string b, string letterSet)
    {
        int totalDist = 0;;
        for (int i = 0; i < letterSet.size(); ++i)
        {
            int n1 = 0;
            int n2 = 0;
            for(int j = 0; j < a.size(); j++)
            {
                char temp = toupper(letterSet[i]);
                if( letterSet[i] == a[j] || temp == a[j])
                {
                    n1++;
                }
            }
            for(int j = 0; j < b.size(); j++)
            {
                char temp = toupper(letterSet[i]);
                if( letterSet[i] == b[j] || temp == b[j])
                {
                    n2++;
                }
            }
            totalDist = totalDist + static_cast<int>(pow((n1-n2), 2));
        }
        return totalDist;
    }
};