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

class CityMap
{
public:
    string getLegend(vector <string> cityMap, vector <int> POIs)
    {
       map<char, int> myMap;
       map<char, int>::iterator it;
       string finalString = "";
       for (int i = 0; i < cityMap.size(); ++i)
       {
       		for(int j = 0; j < cityMap[i].size(); j++)
       		{
       			if(myMap.find(cityMap[i][j]) == myMap.end())
       				myMap[cityMap[i][j]] = 1;
       			else
       				myMap[cityMap[i][j]] = myMap[cityMap[i][j]] + 1;
       		}
       }
       for (int i = 0; i < POIs.size(); ++i)
       {
       		it = myMap.begin();
       		while(it->second != POIs[i])
       			it++;
       		stringstream ss;
       		ss << it->first;
       		finalString.append(ss.str());
       }
       return finalString;
    }
};
