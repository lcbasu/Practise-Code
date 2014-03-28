#include <iostream>
#include <math.h>

using namespace std;

class Prime
{
public:
	Prime(){}
	int isPrime(int);
};

int main()
{
	Prime obj;
	int count = 0;
	int num = 1;
	while(count <= 10001)
	{
		if(obj.isPrime(num))
			count++;
		num++;
	}
	cout << (num-1) << endl;
	return 0;
}


int Prime::isPrime(int num)
{
	int p = sqrt(num);
	int count = 0;
	for(int i = 1; i <= p; i++)
	{
		if(num%i == 0)
			count++;
	}
	if(count == 1)
		return 1;
	else
		return 0;
}