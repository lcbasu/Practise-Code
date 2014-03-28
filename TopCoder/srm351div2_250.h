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

class RoomNumber
{
public:
    int numberOfSets(int roomNumber)
    {
        int countArr[10];
        for (int i = 0; i < 10; ++i)
        {
        	countArr[i] = 0;
        }
        string roomNumberInString;
        stringstream ss;
        ss << roomNumber;
        ss >> roomNumberInString;

        for (int i = 0; i < roomNumberInString.size(); ++i)
        {
        	ss.str("");
        	ss.clear();
        	int digit;
        	ss << roomNumberInString[i];
        	ss >> digit;
        	countArr[digit] = countArr[digit] + 1;
        }
        int setsReq = 0;
        int tempSet = 0;
        for (int i = 0; i < 10; ++i)
        {
        	if(countArr[i] > setsReq && ((i != 6) || (i != 9)))
        		setsReq = countArr[i];
        	int temp = countArr[6] + countArr[9];
        	if(temp%2 == 0)
        		tempSet = temp/2;
        	else
        		tempSet = temp/2 + 1;
        }
        if(tempSet > setsReq)
        	setsReq = tempSet;
        return setsReq;
    }
};
