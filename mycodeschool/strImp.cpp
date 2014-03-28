#include <iostream>

using namespace std;

int myStrlen(char *C)
{
	int len = 0;
	while(*C != '\0')
	{
		C++;
		len++;
	}
	return len;
}

void myStrcpy(char *src,char *dest)
{
   while(*src != '\0')
   {
   		*dest++ = *src++;
   }
   *dest = '\0';
}

int myStrcmp(char* str1,char *str2)
{
	int diff = 0;
	while(*str1 != '\0' && str2 != '\0')
	{
		diff = *str1-*str2;

		if(diff != 0)
		{
			return diff;
		}
		str1++;
		str2++;
	}
	if(*str1 == '\0' && *str2 == '\0')
	{
		return 0;
	}
	else
		return (*str1-*str2);
}

void myStrcat(char* src,char *dest)
{
	while(*dest != '\0')
		dest++;
	while(*src != '\0')
	{
		*dest++ = *src++;
	}
	*dest = '\0';
}

int myatoi(char *c)
{
	int multiplier = 1;
	char *tmp = c;
	while(*tmp != '\0')
		tmp++;
	tmp--;
	int num = 0;
	int val = 0;
	if(*c == '-')
	{
		while(tmp > c)
		{
			val = *tmp;
			num = num + (val-48)*multiplier;
			multiplier = multiplier * 10;
			tmp--;
		}
		num = num * -1;
	}
	else
	{
		while(tmp >= c)
		{
			val = *tmp;
			num = num + (val-48)*multiplier;
			multiplier = multiplier * 10;
			tmp--;
		}		
	}
	return num;
}


char toUpper(char c)
{
	int ascii = c;
	if(ascii >=97 && ascii <= 122)
	{
		ascii = ascii - 32;
		return (char)ascii;
	}
	else
		return c;
}


void RemoveDuplicates(char *C)
{
	char *newStrPtr = C;
	char *tmp = C+1;
	while(*tmp != '\0')
	{
		if(*tmp != *newStrPtr)
		{
			newStrPtr++;
			*newStrPtr = *tmp;
		}
		tmp++;
	}
	newStrPtr++;
	*newStrPtr = '\0';
}


int main()
{
	char C[] = "Lokesh Basu";
	char s[] = "Lokesh Chandra Basu";
	char d[100];
	myStrcpy(s, d);
	cout << myStrlen(C) << endl;
	cout << d << endl;
	cout << myStrcmp(C,d) << endl;
	cout << myatoi("987") << endl;

	return 0;
}