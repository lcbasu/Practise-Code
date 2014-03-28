#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string S;
		cin >> S;
		int len = S.size();
		string s1, s2;
		s1 = S.substr(0, len/2);
		if(len%2 == 0)
			s2 = S.substr(len/2);
		else
			s2 = S.substr(len/2+1);
		sort(s1.begin(), s1.end());
		sort(s2.begin(), s2.end());
		if(s1.compare(s2) == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}