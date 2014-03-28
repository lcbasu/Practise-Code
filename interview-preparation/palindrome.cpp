#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		int start = 0;
		int end = str.size()-1;
		bool palindrome = true;
		while(end > start)
		{
			if(str[start] != str[end])
			{
				palindrome = false;
				break;
			}
			end--;
			start++;
		}
		if(palindrome)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}
