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

class EllysNewNickname
{
public:
    int getLength(string nickname)
    {
        int nameLen = nickname.size();
        int count = 1;
        for(int i=1; i<nameLen; i++)
        {
        	if(!isVowel(nickname, i) || !isVowel(nickname, i-1) )
        		count++;
        }
        return count;
    }
    bool isVowel(string nickname, int i)
    {
    	if(nickname[i] == 'a' || nickname[i] == 'e' || nickname[i] == 'i' || nickname[i] == 'o' || nickname[i] == 'u' || nickname[i] == 'y')
        	return true;
        return false;
    }
};