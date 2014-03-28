#include <iostream>
#include <cstring>

using namespace std;

void reverse(char*);

void reverse(char *str)
{
	char *pStart, *pEnd;
	char temp;
	unsigned int length = strlen(str);

	pStart = &str[0];	//or we could have used "pStart = str;"
	pEnd = &str[length-1];

	while(pStart<pEnd)
	{
		temp = *pStart;
		*pStart= *pEnd;
		*pEnd = temp;
		pStart++;
		pEnd--;
	}
}

int main()
{
	char *str;
	cin >> str;
	reverse(str);
	cout << str << endl;

	return 0;
}