#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main()
{
	int t_test_cases;
	scanf("%d", &t_test_cases);

	string in_str;

	while(t_test_cases--)
	{
		cin >> in_str;
		for(int i=in_str.length()-1; i>2; i--)
		{
			if((in_str[i] == 'F' || in_str[i] == '?') && (in_str[i-1] == 'E' || in_str[i-1] == '?') && (in_str[i-2] == 'H' || in_str[i-2] == '?') && (in_str[i-3] == 'C' || in_str[i-3] == '?'))
			{
				in_str[i-3] = 'C';
				in_str[i-2] = 'H';
				in_str[i-1] = 'E';
				in_str[i] = 'F';
			}				
		}
		for(int j=0; j<in_str.length(); j++)
		{
			if(in_str[j] == '?')
				in_str[j] = 'A';
		}
		cout << in_str << endl;
	}

	return 0;
}