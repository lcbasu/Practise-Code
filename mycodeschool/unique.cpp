#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		bool ascii[128];
		for (int i = 0; i < 256; i++)
		{
			ascii[i] = false;
		}

		string str;
		cin >> str;

		int len = str.size();

		bool unique = true;
		int asciiVal;
		for (int i = 0; i < len; i++)
		{
			asciiVal = static_cast<int>(str[i]);

			if(ascii[asciiVal])
			{
				unique = false;
				break;	
			}
			else
			{
				ascii[asciiVal] = true;			
			}

		}
		if(unique)
			cout << "UNIQUE" << endl;
		else
			cout << "NOT UNIQUE" << endl;
	}
	return 0;
}