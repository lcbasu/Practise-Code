#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string compress(string str)
{
	string compressedStr = "";

	if(str.size() <= 1)
		return str;
	else
	{
		int prev = 0;
		int curnt = 1;
		int count = 1;
		for (int i = 0; i < str.size(); ++i)
		{
			if(str[prev] == str[curnt])
			{
				count++;
			}
			else
			{
				compressedStr.append(str[prev], 1);
				stringstream ss;
				ss << count;
				compressedStr.append(ss.str());
				count = 1;
			}
			prev++;
			curnt++;
		}		
	}
	return compressedStr;
}

int main()
{
	string result = compress("aabcccccaaa");
	cout << result << endl;
	return 0;
}