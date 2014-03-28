#include <iostream>
#include <cstring>

using namespace std;

void replace(char *str, int realLen)
{
	int nSpace = 0;
	for (int i = 0; i < realLen; ++i)
	{
		if(str[i] == ' ')
			nSpace++;
	}
	int newLen = realLen + 2*nSpace;

	//including the null terminator
	int newEnd = newLen;
	int oldEnd = realLen;
	while(nSpace>0)
	{
		if(str[oldEnd] == ' ')
		{
			nSpace--;
			str[newEnd] = '0';
			str[--newEnd] = '2';
			str[--newEnd] = '%';
			oldEnd--;
			newEnd--;
		}
		else
		{
			str[newEnd] = str[oldEnd];
			oldEnd--;
			newEnd--;
		}
	}
}

int main()
{
	char str[100] = "Lokesh Chandra Basu";
	int realLen = strlen(str);

	cout << "Before : " << str << endl;

	replace(str, realLen);

	cout << "After : " << str << endl;

	return 0;
}