#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int aplhaCount[256];
		for (int i = 0; i < 256; ++i)
		{
			aplhaCount[i] = 0;
		}
		string str1, str2;
		cin >> str1 >> str2;
		int len1 = str1.size();
		int len2 = str2.size();
		bool anagram = true;
		if(len1 == len2)
		{
			for (int i = 0; i < len1; ++i)
			{
				aplhaCount[static_cast<int>(str1[i])]++;
			}
			for (int i = 0; i < len1; ++i)
			{
				aplhaCount[static_cast<int>(str2[i])]--;
				if(aplhaCount[static_cast<int>(str2[i])] < 0)
				{
					anagram = false;
					break;
				}
			}			
		}
		else
			anagram = false;
		if(anagram)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}