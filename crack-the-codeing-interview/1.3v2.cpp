#include <iostream>
#include <cstring>
#include <algorithm>


using namespace std;

bool isPermutation(char *str1, char *str2)
{
	bool result = true;

	int s1 = strlen(str1);
	int s2 = strlen(str2);
	if(s1 != s2)
		result = false;
	else
	{
		sort(str1, str1+s1);
		sort(str2, str2+s2);
		for (int i = 0; i < s1; ++i)
		{
			if(str1[i] != str2[i])
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
	char str1[] = "Lokesh";
	char str2[] = "Lokesw";
	bool result = isPermutation(str1, str2);
	if(result)
		cout << "Permutation\n";
	else
		cout << "Not Permutation\n";
	return 0;
}	
