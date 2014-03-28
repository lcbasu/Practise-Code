#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool isMatching(char a, char b)
{
	if(a == '[' && b == ']')
		return true;
	else if(a == '{' && b == '}')
		return true;
	else if(a == '(' && b == ')')
		return true;		
	else
		return false;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string str;
		cin >> str;
		bool crctExp = true;
		vector<char> stack;
		for (int i = 0; i < str.size(); ++i)
		{
			if(str[i] == '[' || str[i] == '{' || str[i] == '(')
				stack.push_back(str[i]);
			else if(str[i] == ']' || str[i] == '}' || str[i] == ')')
			{
				if(stack.empty())
				{
					crctExp = false;
					break;
				}
				else
				{
					char tmp = stack.back();
					stack.pop_back();
					if(!isMatching(tmp, str[i]))
					{
						crctExp = false;
						break;
					}
				}
			}
		}
		if(stack.empty() && crctExp)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
	return 0;
}