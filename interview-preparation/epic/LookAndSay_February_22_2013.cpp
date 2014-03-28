#include <iostream>
#include <sstream>
#include <string>
#include <cstdio>

using namespace std;


string convert(string nStr)
{
	if(nStr.size()==0)
		return nStr;
	stringstream ss;
	nStr = ss.str();
	cout << "nStr : " << nStr << endl;
	int len = nStr.size();
	cout << "len : " << len << endl;
	string nConverted = "";
	for(int i = 0; i < len; i++)
	{
		ss.str("");
		ss << nStr[i];
		string dig = ss.str();
		int count = 1;
		while(i+1 < len && nStr[i+1] == nStr[i])
		{
			count++;
			i++;
		}
		ss.str("");
		ss << count;
		nConverted.append(ss.str());
		nConverted.append(dig);
	}
	return nConverted;
}

void printPatter(int n, int count)
{
	stringstream ss;
	ss << n;
	string nStr = ss.str();
	while(count--)
	{
		cout << nStr << endl;
		nStr = convert(nStr);
		cout << nStr << endl;
	}
}

int main()
{
	printPatter(1, 10);
	return 0;
}
