#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void reverse(char *start, char *end)
{
	char tmp;
	while(end > start)
	{
		tmp = *start;
		*start = *end;
		*end = tmp;
		start++;
		end--;
	}
}

void reverseSentence(char *str)
{
	//cout << str << endl;
	char *temp = str;
	char *start = str;
	while(*temp)
	{
		temp++;
		if(*temp == '\0')
		{
			reverse(start, temp-1);
		}
		else if(*temp == ' ')
		{
			
			reverse(start,temp-1);
			start = temp+1;
		}
	}
	reverse(str, temp-1);
}

int main()
{
	int t;
	cin >> t;
	do
	{
		string str;
		getline(cin, str);
		int len = str.size();
		char c[len+1];
		for (int i = 0; i < len; ++i)
		{
			c[i] = str[i];
		}
		c[len] = '\0';
		reverseSentence(c);
		cout << c << endl;
	}while(t--);
	return 0;
}

