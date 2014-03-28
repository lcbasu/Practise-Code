#include <iostream>

using namespace std;

void reverse(char *str)
{
	char *end = str;
	while(*(end+1) != '\0')
	{
		end++;
	}
	while(str<end)
	{
		char tmp = *str;
		*str = *end;
		*end = tmp;
		str++;
		end--;
	}
}

int main()
{
	char str[] = "Lokesh";
	cout << "Prev :\t" << str << endl;
	reverse(str);
	cout << "New :\t" << str << endl;

	return 0;
}