#include <iostream>
#include <string>

using namespace std;

bool isPalindrom(string str, int start, int end)
{
	while(end>start)
	{
		if(str[start] != str[end])
			return false;
		end--;
		start++;
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		int largest = 1;
		for (int i = 0; i < str.size(); i++)
		{
			for(int j = str.size(); j > i; j-- )
			{
				if(isPalindrom(str, i, j))
				{
					largest = largest > (j-i+1) ? largest : (j-i+1);
				}
			}
		}
		cout << largest << endl;
	}
	return 0;
}
