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

using namespace std;

class Trekking
{
public:
	int findCamps(string trail, vector <string> plans)
    {
    	int min_stay = trail.size() + 50;
    	int count = 0;
        for (int i = 0; i < plans.size(); i++)
        {
        	string temp_plan = plans[i];
        	int temp_min_stay = 0;
        	bool in_break_mode = false;
        	for(int j = 0; j < trail.size(); j++ )
        	{
        		if(trail[j] == '^' && temp_plan[j] == 'C')
        		{
        			count = count + 1;
        			in_break_mode = true;
        			break;
        		}
        		if(temp_plan[j] == 'C')
        		{
        			temp_min_stay = temp_min_stay + 1;
        		}
        	}
        	if(temp_min_stay < min_stay  && !in_break_mode)
        		min_stay = temp_min_stay;
        }
        if(count == plans.size())
        	min_stay = -1;
        return min_stay;
    }
};