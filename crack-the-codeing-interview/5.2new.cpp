#include <iostream>
#include <cstdio>

using namespace std;

void binaryForDouble(double n)
{
	int count = 0;
	int arr[32];
	while(n != 0 && count <= 32)
	{
		n = n*2;
		if(count > 32)
			break;
		if(n >= 1)
		{
			arr[count] = 1;
			n = n - 1.0;
		}
		else
			arr[count] = 0;
		count++;
	}
	if(count > 32)
		printf("ERROR\n");
	else
	{
		for (int i = 0; i < count; ++i)
		{
			printf("%d\t", arr[i]);
		}
	}
}


int main()
{
	binaryForDouble(.1875);
	return 0;
}