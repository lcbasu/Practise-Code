#include <iostream>

using namespace std;

int fact[200];


void calcFactorial(int n, int *startIndex)
{
	for (int i = n-1; i > 0; i--)
	{
		int carry = 0;
		for(int j = 199; j >= *startIndex; j--)
		{
			cout << "Start Index : " << *startIndex << endl; 
			int mul = fact[j]*i;
			int tmp = mul + carry;
			if(tmp>9)
			{
				fact[j] = tmp%10;
				carry = tmp/10;
			}
			else
			{
				fact[j] = tmp;
				carry = 0;
			}
		}
		if(carry>0)
		{
			while(carry>0)
			{
				cout << "Start Index inside carry >0 : " << *startIndex << endl; 
				*startIndex--;
				cout << "Start Index inside carry >0 : " << *startIndex << endl; 
				fact[*startIndex] = carry%10;
				carry = carry/10;
			}
		}
	}
	for (int i = *startIndex; i < 200; ++i)
	{
		cout << fact[i];
	}
	cout << endl;
}

int main()
{
	for (int i = 0; i < 200; ++i)
	{
		fact[i] = 0;
	}

	int t;
	cin >> t;

	while(t--)
	{
		int n;
		cin >> n;
		int tmp = n;
		int startIndex = 199;
		while(n/10>0)
		{
			fact[startIndex] = n%10;
			startIndex--;
			n = n/10;
		}
		if(n>0)
		{
			fact[startIndex] = n;	
		}
		n = tmp;

		for (int i = startIndex; i < 200; ++i)
		{
			cout << fact[i];
		}
		cout << endl;

		cout << "Start Index : " << startIndex << endl; 

		calcFactorial(n, &startIndex);
	}

	return 0;
}