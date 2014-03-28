#include <iostream>

#define INFI 999999

using namespace std;

void extended_bottom_up_cut_rod(int p[], int n, int r[], int s[]);
void print_optimal_sizes(int s[], int n);

void extended_bottom_up_cut_rod(int p[], int n, int r[], int s[])
{
	r[0] = 0;
	s[0] = 0;
	for (int i = 1; i <=n; i++)
	{
		int q = -INFI;
		for(int j = 1; j<=i; j++)
		{
			if(q< p[j]+r[i-j])
			{
				q = p[j]+r[i-j];
				s[i] = j;
			}
		}
		r[i] = q;
	}
}

void print_optimal_sizes(int s[], int n)
{
	while(n>0)
	{
		cout << s[n] << " ";
		n = n - s[n];
	}
	cout << endl;
}

int main()
{
	int p[] = {0,1,5,8,9,10,17,17,20,24,30};

	int r[11];
	int s[11];

	extended_bottom_up_cut_rod(p,7,r,s);

	cout << "Optimal Revenue : " << r[7] << endl;
	print_optimal_sizes(s,7);


	return 0;
}