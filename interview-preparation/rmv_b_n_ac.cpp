#include <iostream>
#include <string>

using namespace std;

#define ONE 1
#define TWO 2

void removeChar(char *str)
{
	int i = 0;
	int j = 0;
	int state = 1;
	while(str[i] != '\0')
	{
		if(state == 1 && str[i] != 'a' && str[i] != 'b')
		{
			str[j] = str[i];
			j++;
		}
		if(state == 2 && str[i] != 'c')
		{
			str[j] = 'a';
			j++;
			if(str[i] != 'a' && str[i] != 'b')
			{
				str[j] = str[i];
				j++;
			}
		}
		state = (str[i] == 'a') ? 2 : 1;		
		i++;
	}
	if(state == 2)
	{
		str[j] = 'a';
		j++;
	}
	str[j] = '\0';
}

int main()
{
	char str[] = "acabbsbcdeaac";
	removeChar(str);
	cout << str << endl;
	return 0;
}
