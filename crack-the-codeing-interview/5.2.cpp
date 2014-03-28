#include <iostream>
#include <string>

using namespace std;

string conversion(double num)
{
	string result = "0.";
	while(true)
	{
		double mul = num*2;
		double s,t;
		if(mul >= 1)
		{
			s = 1;
			result.append("1");
		}
		else
		{
			s = 0;
			result.append("0");
		}
		t = mul - s;
		cout << "t :" << t << "\ns :" << s << "\n" << endl;
		if(t!=0 && result.size() == 32)
			return "ERROR";
		if(t==0)
			return result;
		num = t;
	}
}

int main()
{
	double num = .8125;
	string conversionResult = conversion(num);
	cout << "Output : " << conversionResult << endl;
	return 0;
}