#include <iostream>
using namespace std;

int main()
{
	int n;
	cin >> n;

	int sum=0, rem=0;
	int factNum[200];

	for (int k = 0; k < 200; k++)
	{
		factNum[k] = 0;
	}
	factNum[0] = 1;
	int k,count=0;
	for (int l = 2; l <= n; l++)
	{
		k = 0;
		sum = 0;
		rem = 0;
		while(k<200)
		{
			sum = factNum[k]*l + rem;
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
	for(int m =199; m >= 0; m--)
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