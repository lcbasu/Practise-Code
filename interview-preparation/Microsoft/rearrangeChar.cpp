#include <iostream>

using namespace std;

void correct(char str[], int startIndex, int endIndex)
{
	while(startIndex < endIndex)
	{
		char tmp = str[startIndex];
		str[startIndex] = str[endIndex];
		str[endIndex] = tmp;
		startIndex++;
		endIndex--;
	}
}

void rearrange(char str[], int n)
{
	int startIndex = -1;
	int endIndex = -1;

	//to get start index
	char ch = str[0];
	int i = 0;
	for( ; i < n; i++, ch++)
	{
		if(i+1 < n)
		{
			if(str[i+1] != ch+1)
			{
				startIndex = i+1;
				break;
			}
		}
	}

	//to find the end index
	ch = str[n-1];
	i = n-1;
	for( ; i >=0; i--, ch--)
	{
		if(i-1 >= 0)
		{
			if(str[i-1] != ch-1)
			{
				endIndex = i-1;
				break;
			}
		}
	}

	if(startIndex != -1 && endIndex != -1)
	{
		correct(str, startIndex, endIndex);
	}

	//cout << "SI : " << startIndex << endl;
	//cout << "EI : " << endIndex << endl;
}

int main()
{
	char str[] = "abcedfg";
	int n = sizeof(str)/sizeof(str[0]);
	cout << str << endl;
	rearrange(str, n-1);
	cout << str << endl;
	return 0;
}
