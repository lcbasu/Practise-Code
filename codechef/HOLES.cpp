#include <iostream>
#include <string>

using namespace std;

int noOfHoles(char c)
{
	if(c == 'B')
		return 2;
	else if(c == 'A' || c == 'D' || c == 'O' || c == 'P' || c == 'Q' || c == 'R')
		return 1;
	else
		return 0;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string text;
		cin >> text;
		int count = 0;
		for (int i = 0; i < text.size(); ++i)
		{
			count += noOfHoles(text[i]);
		}
		cout << count << endl;
	}
	return 0;
}
