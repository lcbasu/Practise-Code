#include <iostream>

#define ulli unsigned long long int

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		ulli n, k;
		cin >> n >> k;
		ulli student, teacher;
		if(n == 0 && k == 0)
		{
			student = 0;
			teacher = 0;
		}
		else if(k==0)
		{
			student = 0;
			teacher = n;
		}
		else if(n==0)
		{
			student = 0;
			teacher = 0;			
		}
		else
		{
			student = n/k;
			teacher = n%k;
		}
		cout << student << " " << teacher << endl;
	}
	return 0;
}