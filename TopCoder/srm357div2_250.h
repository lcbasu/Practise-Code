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

class MnemonicMemory
{
public:
    string getPhrase(string number, vector <string> dictionary)
    {
        sort(dictionary.begin(), dictionary.end());
        vector<int> usedIndex;
        vector<int>::iterator it;
        string finalString = "";
        for (int i = 0; i < number.size(); ++i)
        {
        	stringstream ss;
        	int mnemonic;
        	ss << number[i];
        	ss >> mnemonic;
        	for(int j = 0; j < dictionary.size(); j++)
        	{
        		string temp = dictionary[j];
        		if(temp.size() == mnemonic)
        		{
        			it = find (usedIndex.begin(), usedIndex.end(), j);
        			if(it == usedIndex.end())
        			{
        				usedIndex.push_back(j);
        				finalString.append(dictionary[j]);
        				finalString.append(" ");
        			}
        		}
        	}
        }
        return finalString;
    }
};
