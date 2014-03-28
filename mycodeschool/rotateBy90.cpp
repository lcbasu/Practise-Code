#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		int arr[50][50];
		for (int i = 0; i < n; i++)
		{
			for(int j = 0; j < n; j++) 
				cin >> arr[i][j];
		}
		cout << endl;
		for (int i = 0; i < n; i++)
		{
			for(int j = n-1; j >= 0; j--)
			{
				if(j==0)
					cout << arr[j][i];
				else
					cout << arr[j][i] << " ";
			}
			cout << endl;
		}	
	}
	return 0;
}