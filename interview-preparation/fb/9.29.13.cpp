#include <iostream>
#include <string>

using namespace std;

string eraseSubStr(string mainStr, string subStr)
{
	if(subStr.size() == 0)
		return mainStr;
	if(subStr.size() > mainStr.size())
		return "-1";
	int startIndex = mainStr.find(subStr);
	if(startIndex < 0)
		return "-1";
	else
		return mainStr.erase(startIndex, subStr.size());
}


int main()
{
	cout << eraseSubStr("Lokesh", "L") << endl;
	return 0;
}
