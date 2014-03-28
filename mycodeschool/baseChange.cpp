#include <iostream>
#include <string>
#include <cmath>
#include <sstream>
#include <vector>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string n;
		float a;
		int b;

		cin >> n >> a >> b;

		long long int toDecimal = 0;
		int digValue;
		int len = n.size();

		//	to base 10
		if(a != 10)
		{
			for (int i = 0; i < len; i++)
			{
				digValue = (int)n[len-1-i];

				if(digValue >= 65 && digValue <= 90)
					digValue = (int)n[len-1-i] - 55;
				else if(digValue >= 48 && digValue <= 57)
					digValue = (int)n[len-1-i] - 48;
				toDecimal = toDecimal + (digValue*pow(a,i));
			}
		}
		else
		{
			stringstream ss;
			ss << n;
			ss >> toDecimal;
		}

		//	to base b
		vector<string> newNum;
		while(toDecimal > 0)
		{
			int rmndr = toDecimal % b;
			toDecimal = toDecimal / b;
			if(rmndr > 9 && rmndr < 36)
				rmndr = rmndr + 55;
			else
				rmndr = rmndr + 48;

			stringstream ss;
			string cNum;
			ss <<  (char)rmndr;
			ss >> cNum;
			newNum.push_back(cNum);
		}
		if(!newNum.empty())
		{
			for (int i = newNum.size()-1; i >= 0; i--)
				cout << newNum[i];			
		}
		else
			cout << toDecimal;
		cout << endl;
	}
	return 0;
}
