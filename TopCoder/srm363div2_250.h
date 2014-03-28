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

class MirroredClock
{
public:
    string whatTimeIsIt(string time)
    {
        string h = time.substr(0,2);
        string m = time.substr(3,2);
        stringstream ss;
        int intH, intM;
        ss << h;
        ss >> intH;
        ss.str("");
        ss.clear();
        ss << m;
        ss >> intM;
        ss.str("");
        ss.clear();
        string newTime = "";
        if(intM == 0)
        {
            if(intH = 0)
                newTime.append(time);
            else
            {
                intH = 12-intH;
                ss << intH;
                newTime.append(ss.str());
                newTime.append(":");
                newTime.append(m);
            }
        }
        else
        {
                intH = 11-intH;
                ss << intH;
                newTime.append(ss.str());
                ss.str("");
                ss.clear();

                intM = 60 - intM;
                ss << intM;
                newTime.append(":");
                newTime.append(ss.str());
        }
        return newTime;
    }
};
