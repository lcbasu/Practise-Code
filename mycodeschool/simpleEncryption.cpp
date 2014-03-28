#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int key;
		cin >> key;
		string encryptedStr;
		cin >> encryptedStr;
		int intVal;
		int len = encryptedStr.size();
		int diff = 0;
		int newIntVal;
		for (int i = 0; i < len; ++i)
		{
			intVal = encryptedStr[i];
			newIntVal = intVal - key;
			if(newIntVal < 65)
			{
				diff = 65 - newIntVal;
				newIntVal = 90 - (diff - 1);
			}
			stringstream ss;
			string cNum;
			ss <<  (char)newIntVal;
			ss >> cNum;
			cout << cNum;			
		}
		cout << endl;
	}
	return 0;
}