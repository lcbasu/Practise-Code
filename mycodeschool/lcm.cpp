#include <iostream>
#define LL long long int


using namespace std;

LL gcd(LL a, LL b)	//Euclidean Algorithm
{
	if(a < b)
	{
		LL tmp = a;
		a = b;
		b = tmp;
	}
	if(b == 0)
		return a;
	return gcd(b, a%b);
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int X;
		cin >> X;
		LL lcm = 1; 
		for (int i = 2; i <= X; ++i)
		{
			lcm = (lcm*i)/gcd(lcm, i);
		}
		cout << lcm << endl;
	}
	return 0;
}