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

class AzimuthMonitoring
{
public:
    int getAzimuth(vector <string> instructions)
    {
        int finalDirection = 0;
        for (int i = 0; i < instructions.size(); ++i)
        {
        	if(instructions[i] == "LEFT")
        		finalDirection = finalDirection - 90;
        	else if(instructions[i] == "RIGHT")
        		finalDirection = finalDirection + 90;
        	else if(instructions[i] == "TURN AROUND")
        		finalDirection = finalDirection + 180;        
        	else if(instructions[i] == "HALT")
        		break;
        	else
        	{
        		stringstream ss;
        		string inst;
        		int angle;
        		ss << instructions[i];
        		ss >> inst >> angle;
        		if(inst == "LEFT")
        			finalDirection = finalDirection - angle;
        		else if(inst == "RIGHT")
        			finalDirection = finalDirection + angle;
        	}        			
        }
        //return finalDirection; [first attempt answer, it should be modulo 360 because azimuthal should be [0,360) ]

        return finalDirection%360;

    }
};
