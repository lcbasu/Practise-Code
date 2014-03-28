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
		while(end > start)
		{
			char tmp = str[start];
			str[start] = str[end];
			str[end] = tmp;
			end--;
			start++;
		}
		cout << str << endl;

	}
	return 0;
}
