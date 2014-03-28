#include <iostream>
#include <cstring>

using namespace std;

int ascii[256];

bool isPermutation(char *str1, char *str2)
{
	bool result = true;
	int s1 = strlen(str1);
	int s2 = strlen(str2);
	if(s1 != s2)
		result = false;
	else
	{
		for (int i = 0; i < s1; ++i)
		{
			int tmp = str1[i];
			ascii[tmp]++;
		}
		for (int i = 0; i < s2; ++i)
		{
			int tmp = str2[i];
			if(--ascii[tmp] < 0)
			{
				result = false;
				break;
			}
		}
	}
	return result;
}

int main()
{
	for (int i = 0; i < 256; ++i)
	{
		ascii[i] = 0;
	}
	char str1[] = "Lokesh";
	char str2[] = "Lokesh";
	bool result = isPermutation(str1, str2);
	if(result)
		cout << "Permutation\n";
	else
		cout << "Not Permutation\n";
	return 0;
}