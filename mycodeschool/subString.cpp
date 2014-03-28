#include <iostream>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string s1, s2;
		cin >> s1 >> s2;
		string tmp;
		if(s1.size() < s2.size())
		{
			tmp = s1;
			s1 = s2;
			s2 = tmp;
		}
		int count = 0;
		for (int i = 0; i < s1.size() && count < s2.size(); ++i)
		{
			if(s1[i] == s2[count])
			{
				count++;
				continue;
			}
		}
		if(count == s2.size())
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}