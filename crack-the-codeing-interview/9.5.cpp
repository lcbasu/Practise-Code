#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;


void sortStr(char *str, int n)
{
	sort(str, str+n);
}


void swap(char *a, char *b)
{
	char tmp = *a;
	*a = *b;
	*b = tmp;
}

void reverse(char str[], int start, int end)
{
	while(start <= end)
	{
		char tmp = str[start];
		str[start] = str[end];
		str[end] = tmp;
		start++;
		end--;
	}
}

void allPermutation(char str[], int n)
{
	sortStr(str, n);
	cout << str << endl;
	int count = 0;
	while(true)
	{
		int k;
		for(k = n-2; k >= 0; k--)
		{
			if(str[k] < str[k+1])
				break;
		}
		if(k < 0)
			break;	//reached the end permutated string so break outer loop

		count++; //found another permutation

		int l;
		for(l = n-1; l > k; l--)
		{
			if(str[k] < str[l])
				break;
		}
		swap(&str[k], &str[l]);
		reverse(str, k+1, n-1);
		cout << str << endl;
	}
}

int main()
{
	char str[] = "123";
	int n = strlen(str);
	allPermutation(str, n);
	return 0;
}
