#include <iostream>
#include <stack>
#include <string>
#include <map>

using namespace std;

map<char, int> precedence;

void setPrecedence()
{
	precedence[')'] = 8;
	precedence['^'] = 7;
	precedence['*'] = 6;
	precedence['/'] = 5;
	precedence['%'] = 4;
	precedence['+'] = 3;
	precedence['-'] = 2;
	precedence['('] = 1;
}

bool isOperator(char c)
{
	if(c == '(' || c == ')' || c == '^' || c == '*' || c == '/' || c == '%' || c == '+' || c == '-')
		return true;
	return false;
}

void reversePolishNotation(string in)
{
	int len = in.size();
	if(len <=1)
		cout << in << endl;
	stack<char> st;
	for (int i = 0; i < len; ++i)
	{
		if(!isOperator(in[i]))
			cout << in[i];
		else
		{
			if(in[i] == ')')
			{
				while(st.top() != '(')
				{
					cout << st.top();
					st.pop();
				}
				st.pop();
			}
			while(!st.empty() && precedence[st.top()] < precedence[in[i]])
			{
				if(st.top() != '(')
					cout << st.top();
				st.pop();
			}
			if(in[i] != ')')
				st.push(in[i]);
		}
	}
	while(!st.empty())
	{
		if(st.top() != '(')
			cout << st.top();
		st.pop();
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string in;
		cin >> in;
		reversePolishNotation(in);
	}
	return 0;
}