#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	ifstream inData;
	inData.open("11.txt");

	int a[20][20];

	int largest = 0;
	
	int i,j,k,l,m;
	for(i=0; i<20; i++)
	{
		for(j=0; j<20; j++)
			inData >> a[i][j];
	}

	int tmp = 0;

	for(m=0; m<20; m++)
	{
		for(i=0,j=1,k=2,l=3; l<20; i++, j++, k++, l++)
		{
			tmp = a[p][i]*a[p+1][j]*a[p+2][k]*a[p+3][l];
			if(tmp>largest)
				largest = tmp;
		}
	}

	cout << largest << endl;;
	return 0;
}