#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <cstring>

using namespace std;

void removeDuplicates(char arr[], int n)
{
	bool ascii[256];
	memset(ascii, false, 256);

	int currIndex = 0;
	for(int i = 0; i < n; i++)
	{
		char ch = arr[i];
		int asciiValue = (int)ch;
		if(asciiValue >= 65 && asciiValue <= 90)
		{
			asciiValue += 32;
		}
		if(ascii[asciiValue] == false)
		{
			ascii[asciiValue] = true;
			arr[currIndex] = arr[i];
			currIndex++;
		}
	}
	arr[currIndex] = arr[n];
}

int main()
{
	char str[] = "Today is the day";
	int n = sizeof(str)/sizeof(char);
	cout << "Old :\t";
	cout << str << endl;
	removeDuplicates(str, n);
	cout << "New :\t";
	cout << str << endl;
	return 0;
}
