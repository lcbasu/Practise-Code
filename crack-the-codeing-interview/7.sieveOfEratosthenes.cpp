#include <iostream>
#include <cmath>

using namespace std;

void display(bool, int);

void initialize(bool *flag, int len)
{
	flag[0] = false;
	flag[1] = false;	
	for(int i = 2; i < len; i++)
		flag[i] = true;
}

int getNextPrime(bool *flag, int prime, int n)
{
	for (int i = prime+1; i <= n; i++)
	{
		if(flag[i])
			return i;
	}
	return -1;
}

void display(bool *flag, int len)
{
	for (int i = 0; i < len; ++i)
	{
		cout << i << " :\t";
		if(flag[i])
			cout << "Prime\n";
		else
			cout << "Not Prime\n";
	}
	cout << endl;
}

bool *sieveOfEratosthenes(int n)
{
	bool *flag = new bool[n+1];
	initialize(flag, n+1);
	//display(flag, n+1);
	int prime = 2;
	while(prime <= sqrt(n) && prime >= 2)
	{
		for (int i = prime*2; i <= n; i = i + prime)
		{
			flag[i] = false;
		}
		prime = getNextPrime(flag, prime, n);
	}
	//display(flag, n+1);
	return flag;
}



int main()
{
	int n;
	cout << "N : ";
	cin >> n;
	bool *primeArr = sieveOfEratosthenes(n);
	display(primeArr, n+1);
	return 0;
}