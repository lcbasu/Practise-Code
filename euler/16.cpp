#include <iostream>
using namespace std;

int main()
{
	int sum=0, rem=0;
	int factNum[2000];

	for (int k = 0; k < 2000; k++)
	{
		factNum[k] = 0;
	}
	factNum[0] = 2;
	int k,count=0;

	for (int l = 1; l < 1000; l++)
	{
		k = 0;
		sum = 0;
		rem = 0;
		while(k<2000)
		{
			sum = factNum[k]*2 + rem;
			rem = 0;
			if(sum > 9)
			{
				factNum[k] = sum%10;
				rem = sum/10;
			}
			else
				factNum[k] = sum;
			k++;
		}
	}
	int digSum = 0;
	for(int m =1999; m >= 0; m--)
	{
		if(factNum[m]!=0 || count==1)  
		{
			digSum += factNum[m];
			count = 1;
		}
	}
	cout << digSum << endl;
	cout << endl;
	return 0;
}