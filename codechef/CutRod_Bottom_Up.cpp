#include <iostream>
using namespace std;

#define NEGINFI -99999999

class CutRodBottomUp
{
public:
	CutRodBottomUp(){}

	int bottomUpCutRod(int[], int, int[]);
	int max(int, int);
};

int CutRodBottomUp::bottomUpCutRod(int p[], int n, int r[])
{
	r[0] = 0;
	for (int j = 1; j <= n; j++)
	{
		int q = NEGINFI;
		for(int i = 1; i <= j; i++)
			q = max(q, p[i]+r[j-i]);
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
	cout << obj.bottomUpCutRod(p,n,r);
	return 0;
}
