#include <iostream>
using namespace std;

#define NEGINFI -99999999

class CutRodBottomUp
{
public:
	CutRodBottomUp(){}

	int exBottomUpCutRod(int[], int, int[],int[]);
	int max(int, int);
};

int CutRodBottomUp::exBottomUpCutRod(int p[], int n, int r[], int s[])
{
	r[0] = 0;
	s[0] = 0;
	for (int j = 1; j <= n; j++)
	{
		int q = NEGINFI;
		for(int i = 1; i <= j; i++)
		{
			if(q < p[i]+r[j-i])
			{
				q = p[i]+r[j-i];
				s[j] = i;
			}
		}
		r[j] = q;
	}
	return r[n];
}

int CutRodBottomUp::max(int a, int b)
{
	return (a>b ? a:b);
}

int main()
{
	CutRodBottomUp obj;
	int n;
	cout << "Number of entries for Price table: ";
	cin >> n;
	cout << endl;

	int p[n+1];
	p[0] = 0;

	for(int i = 1; i <= n; i++)
	{
		cout << "P-" << i << " : ";
		cin >> p[i];
		cout << "\n";
	}
	cout << "Find out max revnue for n = ";
	cin >> n;
	int r[n+1];
	int s[n+1];
	obj.exBottomUpCutRod(p,n,r,s);

	cout << "\ni\t|";
	for (int i = 1; i <= n ; i++)
	{
		cout << i << "\t";
	}
	cout << "\n";	

	cout << "r[i]\t|";
	for (int i = 1; i <= n ; i++)
	{
		cout << r[i] << "\t";
	}
	cout << "\n";

	cout << "s[i]\t|";
	for (int i = 1; i <= n ; i++)
	{
		cout << s[i] << "\t";
	}
	cout << "\n";
	return 0;
}
