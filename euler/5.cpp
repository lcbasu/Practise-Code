#include <iostream>

using namespace std;

int main()
{
	int count = 0;
	int num = 10;
	while(1)
	{
		for(int i=1; i<=10; i++)
		{
			if(num % i == 0)
				count++;
			else
				break;
		}
		if(count == 10)
			break;
		else
			count = 0;
		num = num * 10;
	}

	cout << num << endl;
	return 0;
}