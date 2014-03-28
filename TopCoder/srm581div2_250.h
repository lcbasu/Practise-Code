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

class BlackAndWhiteSolitaire
{
public:
    int minimumTurns(string cardFront)
    {
    	int len = cardFront.size();
        char *memory = new char[len];
        for (int i = 0; i < len; ++i)
        {
        	memory[i] = cardFront[i];
        }
        int count = 0;
        for (int i = 1; i < len; ++i)
        {
        	if(memory[i] == memory[i-1] && memory[i] == 'B')
        	{
        		memory[i] = 'W';
        		count++;
        	}
        	else if(memory[i] == memory[i-1] && memory[i] == 'W')
        	{
        		memory[i] = 'B';
        		count++;
        	}        	
        }
        for (int i = 0; i < len; ++i)
        {
        	memory[i] = cardFront[len-i-1];
        }
        int count2 = 0;
        for (int i = 1; i < len; ++i)
        {
        	if(memory[i] == memory[i-1] && memory[i] == 'B')
        	{
        		memory[i] = 'W';
        		count2++;
        	}
        	else if(memory[i] == memory[i-1] && memory[i] == 'W')
        	{
        		memory[i] = 'B';
        		count2++;
        	}        	
        }      
        return count > count2 ? count2:count;
    }
};
