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

class UserName
{
public:
    string newMember(vector <string> existingNames, string newName)
    {
    	string tmpNewName;
        if(!isPresent(existingNames, newName))
        	return newName;
        else
        {
        	int num = 1;
        	while(true)
        	{
        		tmpNewName = newName;
        		stringstream ss;
        		ss << num;
        		string tmp;
        		ss >> tmp;
        		tmpNewName.append(tmp);
		        if(!isPresent(existingNames, tmpNewName))
        			return tmpNewName;
        		num++;
        	}
        }
    }
    bool isPresent(vector <string> existingNames, string username)
    {
    	if(find(existingNames.begin(), existingNames.end(), username) != existingNames.end())
    		return true;
    	return false;
    }
};
