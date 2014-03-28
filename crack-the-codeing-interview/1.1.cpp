#include <iostream>

using namespace std;

bool ascii[256];

int strSize(char *str)
{
	int count = 0;
	while(str)
	{
		count++;
		str++;
	}
	return count;
}

bool allUnique(char *str)
{
	if(strSize(str)>256)
		return false;
	while(str)
	{
		if(ascii[*str] == true)
			return false;
		str++;
	}
	return true;
}

int main()
{
	for (int i = 0; i < 256; ++i)
	{
		ascii[i] = false;
	}
	char str[5] = "LCCB";

	cout << allUnique(str) << endl;
	return 0;
}