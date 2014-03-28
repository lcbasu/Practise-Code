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
#include <locale>

using namespace std;

class SMSLanguage
{
public:
    string translate(string text)
    {
        for (int i = 0; i < text.size(); ++i)
        {
        	unsigned found = text.find('.');
        	if(found != string::npos)
        		text.erase(found,1);
        	found = text.find(',');
        	if(found != string::npos)
        		text.erase(found,1);
        	found = text.find('?');
        	if(found != string::npos)
        		text.erase(found,1);        	        	
        	found = text.find('!');
        	if(found != string::npos)
        		text.erase(found,1);
        	if((int)text[i] >=65 && (int)text[i] <= 90)
        	{
				stringstream ss;
				string temp;
				ss << (char)tolower(text[i]);
				ss >> temp;
				text.replace(i, 1, temp);        		
        	}
        }

        for (int i = 0; i < text.size(); ++i)
        {
        	if(text[i] == 'a'&& text[i+1] == 'n'  && text[i+2] == 'd')
        		text.replace(i, 3, "&");     	
        	if(text[i] == 'a'&& text[i+1] == 't'  && text[i+2] == 'e')
        		text.replace(i, 3, "8");
        	if(text[i] == 'a'&& text[i+1] == 't')
        		text.replace(i, 2, "@");           		     
        	if(text[i] == 'y'&& text[i+1] == 'o'  && text[i+2] == 'u')
        		text.replace(i, 3, "U");         	
        }
        return text;
    }
};
