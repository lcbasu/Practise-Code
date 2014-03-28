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

class SearchBox
{
public:
    int find(string text, string search, string wholeWord, int start)
    {
    	int index = -1;
    	unsigned found;

        if(wholeWord == "N")
        {
        	found = text.find(search, start);
        	if(found != string::npos)
        		index = found;
        }        	
        else if(wholeWord == "Y")
        {
        	found = text.find(search, start);
        	if(found != string::npos)
        	{
        		if(found == 0 && ((int)text[found+search.size()] == 32))	//first word
        			index = found;
        		else if((found+search.size() == text.size()) && ((int)text[found-1] == 32))	//last word
        			index = found;
        		else if(search.size() == text.size())	//only one word in the text
        			index = found;
        		else if(((int)text[found-1] == 32) && ((int)text[found+search.size()] == 32))	//word present elsewhere in the text
        			index = found;
        	}        	
        }
        return index;
    }
};
