#include <iostream>

using namespace std;

int myStrlen(char *C)
{
	int len = 0;
	while(*C != '\0')
		len++;
	return len;
}