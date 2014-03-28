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

class Thimbles
{
public:
    int thimbleWithBall(vector <string> swaps)
    {
    	bool ballIndex[3];
    	ballIndex[0] = true;
    	ballIndex[1] = false;
    	ballIndex[2] = false;
        bool finalIndex = 0;
    	for (int i = 0; i < swaps.size(); ++i)
    	{
    		int firstIndex, secondIndex;
    		string temp;
    		stringstream ss;
    		ss << swaps[i][0];
    		ss >> firstIndex;
    		ss.str("");
    		ss.clear();
    		ss << swaps[i][2];
    		ss >> secondIndex;
            firstIndex--;
            secondIndex--;
    		if(ballIndex[firstIndex] == true || ballIndex[secondIndex] == true)
    		{
    			bool tempBallIndex;
    			tempBallIndex = ballIndex[firstIndex];
    			ballIndex[firstIndex] = ballIndex[secondIndex];
    			ballIndex[secondIndex] = tempBallIndex;
    		}
    	}
    	for (int i = 0; i < 3; ++i)
    	{
    		if(ballIndex[i] == true)
    		{
    			finalIndex = i;
    		}
    	}
        return finalIndex+1;
    }
};
