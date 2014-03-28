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

class MorselikeCode
{
public:
    string decrypt(vector <string> library, string message)
    {
        map<string, char> libraryTable;
        string decryptMessage = "";
        for (int i = 0; i < library.size(); ++i)
        {
        	stringstream ss;
        	ss << library[i];
        	char C;
        	string sequence;
        	ss >> C >> sequence;
        	libraryTable[sequence] = C;
        }
        string tempWord = "";
        for (int i = 0; i < message.size(); i++)
        {
        	while((int)message[i] != 32 && (i != message.size()))
        	{
        		stringstream ss;
        		ss << message[i];
        		tempWord.append(ss.str());
        		i++;
        	}
        	if(libraryTable.find(tempWord) != libraryTable.end())
        	{
        		stringstream ss;
        		ss << libraryTable[tempWord];
        		decryptMessage.append(ss.str());
        	}
        	else
        		decryptMessage.append("?");
        	tempWord = "";
        }
        return decryptMessage;
    }
};
