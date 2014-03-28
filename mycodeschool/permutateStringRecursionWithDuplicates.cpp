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
	char str[] = "mmd";
	permutate(str, 0, 2);
	set<string>::iterator it;
	for(it = memory.begin(); it != memory.end(); it++)
		cout << *it << endl;
	return 0;
}