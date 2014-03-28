#include <iostream>
#include <cstring>
#include <cstdio>

#define RANGE 255

using namespace std;


void countingSort(char *str)
{
	int size = strlen(str);
	char output[size];
	
	int count[RANGE+1];

	memset(count, 0, sizeof(count));

	for (int i = 0; str[i]; ++i)
	{
		count[str[i]]++;
	}

	for (int i = 1; i <= RANGE; ++i)
	{
		count[i] += count[i-1];
	}

	for (int i = 0; str[i]; ++i)
	{
		int index = count[str[i]]-1;
		count[str[i]]--;
		output[index] = str[i];
	}
	for (int i = 0; str[i]; ++i)
	{
		str[i] = output[i];
	}
}

int main()
{
	char str[] = "LokeshChandraBasu";
	printf("Old :\t");
	printf("%s\n", str);
	countingSort(str);
	printf("New :\t");
	printf("%s\n", str);	
	return 0;
}