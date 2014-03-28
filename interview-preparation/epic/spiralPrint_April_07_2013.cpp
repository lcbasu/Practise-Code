#include <iostream>

#define N 5

using namespace std;

int main()
{
	int arr[N][N];
	int count = 1;
	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			arr[i][j] = count++;
	}

	for (int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
			cout << arr[i][j] << " ";
		cout << endl;
	}

	int l = 0;
	int r = N-1;
	int t = 0;
	int b = N-1;
	int dirction = 0; //0-> left to right, 1 -> top to bottom, 2 -> right to left, 3 -> bottom to top
	while(l <= r && t <= b)
	{
		if(dirction == 0)
		{
			for (int i = l; i <= r; i++)
			{
				cout << arr[t][i] << " ";
			}
			t++;
			dirction = 1;
		}
		else if(dirction == 1)
		{
			for (int i = t; i <= b; ++i)
			{
				cout << arr[i][r] << " ";
			}
			r--;
			dirction = 2;
		}
		else if(dirction == 2)
		{
			for (int i = r; i >= l; i--)
			{
				cout << arr[b][i] << " ";
			}
			b--;
			dirction = 3;
		}
		else if(dirction == 3)
		{
			for (int i = b; i >= t; i--)
			{
				cout << arr[i][l] << " ";
			}
			l++;
			dirction = 0;
		}
	}
	return 0;
}