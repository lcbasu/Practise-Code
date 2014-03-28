#include <iostream>

using namespace std;

#define NEGINFI -999999

class CutRod
{
public:
	CutRod(){}

	int memoizedCutRod(int[], int, int[]);
	int memoizedCutRodAux(int[], int, int[]);
	int max(int, int);
};

int CutRod::memoizedCutRod(int p[], int n, int r[])
{
	for (int i = 0; i <= n; i++)
	{
		r[i] = NEGINFI;
	}
	return memoizedCutRodAux(p,n,r);
}

int CutRod::memoizedCutRodAux(int p[], int n, int r[])
{
	int q = NEGINFI;
	if(r[n]>0)
		return r[n];
	if(n == 0)
		return 0;
	else
	{
		q = NEGINFI;
		for (int i = 1; i <= n; i++)
		{
			q = max(q, p[i]+memoizedCutRodAux(p,n-i,r));
		}
	}
	r[n] = q;
	return q;
}

int CutRod::max(int a, int b)
{
	return (a>b ? a:b);
}

int main()
{
	CutRod obj;
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
	cout << obj.memoizedCutRod(p,n,r);
	return 0;
}
