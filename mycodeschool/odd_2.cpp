#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int k;
		cin >> k;
		int count = 0;
		int i;
		for (i = 0; count != k; i++)
		{
			stringstream ss;
			string num;
			ss << i;
			ss >> num;
			bool odd = false;
			ss.str("");
			int digit;
			int countDig = 0;
			for (int j = 0; j < num.size(); j++)
			{
				countDig++;
				ss << num[j];
				ss >> digit;
				ss.str("");
				if(digit%2==0)
				{
					break;
				}
			}
			if(countDig == num.size())
				odd = true;
			if(odd)
				count++;
		}
		cout << i << endl;
	}
	return 0;
}
