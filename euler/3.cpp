#include <iostream>
#include <math.h>

using namespace std;

long long int n = 600851475143;
long long int s = sqrt(n);

class Prime
{
public:
	Prime()
	{}
	int isPrime(int);
};

int Prime::isPrime(int num)
{
	int p = sqrt(num);
	int count = 0;
	for(int i = 1; i <= p; i++)
	{
		if(n%i == 0)
			count++;
	}
	if(count == 1)
		return 1;
	else
		return 0;
}

int main()
{
	Prime obj;
	long long int largest = 1;
	for(int j = 3; j <= s; j = j+2)
	{
		if(obj.isPrime(j))
		{
			while(n%j == 0)
			{
				n = n/j;
				if(j>largest)
					largest = j;
			}
		}
	}
	cout << largest << endl;
	return 0;
}