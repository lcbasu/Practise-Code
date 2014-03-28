#include <iostream>
#include <set>
#include <string>
#include <sstream>

using namespace std;

set<string> memory;

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutate(char *str, int start, int end)
{
	if(start == end)
	{
		stringstream ss;
		ss << str;
		string tmp = ss.str();
		memory.insert(tmp);
	}
	for (int i = start; i <= end; i++)
	{
		swap(&str[start], &str[i]);
		permutate(str, start+1, end);
		swap(&str[start], &str[i]);
	}
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		char *str = new char[6];
		cin >> str;
		int size = 0;
		while(str[size] != '\0')
			size++;
		permutate(str, 0, size-1);
		set<string>::iterator it;
		it = memory.begin();
		cout << *it;
		it++;
		for(it; it != memory.end(); it++)
			cout<< " " << *it;
		cout << endl;
		memory.clear();
	}
	return 0;
}