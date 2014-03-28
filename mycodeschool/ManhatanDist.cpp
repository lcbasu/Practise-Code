#include <iostream>

#define abs(x) x>0?x:-x 

using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void sort(int X[], int Y[], int manhDist[], int n)
{
	if(n<=1)
		return;
	for (int i = 0; i < n; ++i)
	{
		bool noSwapping = true;
		for(int j = 0; j < n-i-1; j++)
		{
			if(manhDist[j] > manhDist[j+1])
			{
				noSwapping = false;
				swap(manhDist[j], manhDist[j+1]);
				swap(X[j], X[j+1]);
				swap(Y[j], Y[j+1]);
			}
			else if(manhDist[j] == manhDist[j+1] && X[j] > X[j+1])
			{
				noSwapping = false;
				swap(manhDist[j], manhDist[j+1]);
				swap(X[j], X[j+1]);
				swap(Y[j], Y[j+1]);
			}
			else if(manhDist[j] == manhDist[j+1] && X[j] == X[j+1] && Y[j] > Y[j+1])
			{
				noSwapping = false;
				swap(manhDist[j], manhDist[j+1]);
				swap(X[j], X[j+1]);
				swap(Y[j], Y[j+1]);
			}						
		}
		if(noSwapping)
			break;
	}
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int *X = new int[n];
		int *Y = new int[n];
		int *manhDist = new int[n];
		for (int i = 0; i < n; i++)
		{
			cin >> X[i] >> Y[i];
			int a = abs(X[i]);
			int b = abs(Y[i]);
			manhDist[i] = a + b;
		}
		sort(X, Y, manhDist, n);
		for (int i = 0; i < n; ++i)
		{
			cout << X[i] << " " << Y[i] << endl;
		}
		cout << endl;
	}
	return 0;
}