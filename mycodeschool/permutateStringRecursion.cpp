#include <iostream>

using namespace std;

void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void permutate(char *str, int start, int end)
{
	if(start == end)
		cout << str << endl;
	for (int i = start; i <= end; i++)
	{
		swap(&str[start], &str[i]);
		permutate(str, start+1, end);
		swap(&str[start], &str[i]);
	}
}


int main()
{
	char str[] = "aab";
	permutate(str, 0, 2);
	return 0;
}