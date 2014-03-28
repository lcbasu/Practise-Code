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

class MatchMaking
{
public:

	void swap(string *a, string *b)
	{
		string tmp = *a;
		*a = *b;
		*b = tmp;
	}

	void BubbleSort(vector <string> namesWomen, vector <string> answersWomen, int n)
	{
		if(n<=1)
			return;
		for (int i = 0; i < n; ++i)
		{
			bool noSwapping = true;
			for(int j = 0; j < n-i-1; j++)
			{
				if(namesWomen[j].compare(namesWomen[j+1]) < 0)
				{
					noSwapping = false;
					swap(&namesWomen[j+1], &namesWomen[j]);
					swap(&answersWomen[j+1], &answersWomen[j]);
				}
			}
			if(noSwapping)	//break if any of the pass happened without any swap, that means that the array is already sorted
				break;
		}
	}


    string makeMatch(vector <string> namesWomen, vector <string> answersWomen, vector <string> namesMen, vector <string> answersMen, string queryWoman)
    {
        map<string, string> match;
        bool *alreadyMatched = new bool[namesMen.size()];
        for (int i = 0; i < namesMen.size(); ++i)
        {
        	alreadyMatched[i] = false;
        }
        BubbleSort(namesWomen, answersWomen, namesWomen.size());
        for (int i = 0; i < namesWomen.size(); i++)
        {
        	string currentWomen = namesWomen[i];
        	string currentWomenAns = answersWomen[i];
        	int maxMatch = 0;
        	int maxMatchIndex = 0;
        	for(int j = 0; j < namesMen.size(); j++)
        	{
        		string currentMen = namesMen[j];
        		string currentMenAns = answersMen[j];
        		if(alreadyMatched[j])
        			continue;
        		int currentMatch = totalMatch(currentWomenAns, currentMenAns);
        		if(currentMatch > maxMatch)
        		{
        			maxMatchIndex = j;
        			maxMatch = currentMatch;
        			match[currentWomen] = currentMen;
        		}
        		else if(currentMatch == maxMatch && currentMen.compare(namesMen[maxMatchIndex]) < 0)
        		{
        			maxMatchIndex = j;
        			maxMatch = currentMatch;
        			match[currentWomen] = currentMen;        			
        		}
        	}
        	alreadyMatched[maxMatchIndex] = true;
        }
        return match[queryWoman];
    }
    int totalMatch(string ans1, string ans2)
    {
    	int count = 0;
    	for (int i = 0; i < ans1.size(); ++i)
    	{
    		if(ans1[i] == ans2[i])
    			count++;
    	}
    	return count;
    }
};
