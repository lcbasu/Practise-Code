#include <iostream>

using namespace std;

void allPermutation(char str[], int leftParenRemaining, int rightParenRemaining, int count)
{
	if(leftParenRemaining < 0 || leftParenRemaining > rightParenRemaining)
		return;
	if(leftParenRemaining == 0 && rightParenRemaining == 0)
	{
		for(int i = 0; i < count; i++)
			cout << str[i];
		cout << endl;
	}
	else
	{
		if(leftParenRemaining > 0)
		{
			str[count] = '(';
			allPermutation(str, leftParenRemaining-1, rightParenRemaining, count+1);
		}
		if(rightParenRemaining > leftParenRemaining)
		{
			str[count] = ')';
			allPermutation(str, leftParenRemaining, rightParenRemaining-1, count+1);
		}
	}
}

int main()
{
	char str[100];
	allPermutation(str, 3, 3, 0);
	return 0;
}
