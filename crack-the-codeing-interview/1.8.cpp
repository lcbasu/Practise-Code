#include <iostream>
#include <string>

using namespace std;

bool isSubString(string str1, string str2)
{
	bool result = true;
	int remainingLen = str1.size();
	int startIndex = 0;
	while(remainingLen >= str2.size())
	{
		int count = 0;
		for (int i = 0; i < str2.size() && (remainingLen >= str2.size()); ++i)
		{
			if(str1[startIndex] == str2[i])
			{
				count++;
			}
			else
			{
				i = 0;
				count = 0;
			}
			startIndex++;
			remainingLen--;
		}
	}
	return result;
}

bool isRotation(string str1, string str2)
{
	bool result;
	if(str1.size() == str2.size() && str1.size() > 1)
	{
		string newStr1 = str1.append(str1);
		result = isSubString(newStr1, str2);
	}
	return result;
}

int main()
{
	bool result = isRotation("suLokeshBp", "LokeshBasu");
	if(result)
		cout << "Rotation" << endl;
	else
		cout << "Not Rotation" << endl;
	return 0;
}