#include <iostream>

using namespace std;

class Palindrome
{
public:
	Palindrome(){}

	int isPalindrome(int);
};

int Palindrome::isPalindrome(int n)
{
	int num = n;
	int rev = 0, dig = 0;
	while(n>0)
	{
		dig = n%10;
		rev = rev*10 + dig;
		n = n/10;
	}
	if(num == rev)
		return 1;
	else
		return 0;
}

int main()
{
	Palindrome obj;
	int i, j, n, largest = 0;
	for(i=100; i<1000; i++)
	{
		for(j=100; j<1000; j++)
		{
			n = i*j;
			if(obj.isPalindrome(n))
			{
				if(n>largest)
					largest = n;
			}
		}
	}

	cout << largest << endl;

	return 0;
}