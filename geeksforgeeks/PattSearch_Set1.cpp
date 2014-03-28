#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;

void patterSearch(char *patt, char *text)
{
	int m = strlen(patt);
	int n = strlen(text);

	for(int i = 0; i <= n-m; i++)
	{
		int j;
		for(j = 0; j < m; j++)
		{
			if(text[i+j] != patt[j])
				break;
		}
		if(j==m)
			cout << "Found pattern at index :\t" << i << endl;
	}
}

int main()
{
	char *text = "LokeshBasuLokesh";
	char *patt = "Lokesh";
	patterSearch(patt, text);
	return 0;
}
