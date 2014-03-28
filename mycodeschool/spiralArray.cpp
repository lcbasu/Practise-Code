#include <iostream>

using namespace std;

void printEl(int el, bool *prevEl)
{
	//prevElement implies that whether there is any element befor it or not so if true then it's not the first element that is printed
	if(!*prevEl)
	{
		cout << el;
		*prevEl = true;
	}
	else
		cout << " " << el;
}

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int m, n;
		cin >> m >> n;
		int arr[100][100];
		for (int i = 0; i < m; i++)
		{
			for(int j = 0; j < n; j++)
				cin >> arr[i][j];
		}

		int top, btm, lt, rt;
		top = 0;
		btm = m-1;
		lt = 0;
		rt = n-1;
		int dir = 0;
		bool prevEl = false;
		
		while(top <= btm && lt <= rt)
		{
			if(dir == 0)
			{
				for (int i = lt; i <= rt; i++)
					printEl(arr[top][i], &prevEl);
				dir = 1;
				top++;
			}
			else if(dir == 1)
			{
				for (int i = top; i <= btm; i++)
					printEl(arr[i][rt], &prevEl);
				dir = 2;
				rt--;
			}
			else if(dir == 2)
			{
				for (int i = rt; i >= lt; i--)
					printEl(arr[btm][i], &prevEl);
				dir = 3;
				btm--;				
			}
			else if(dir == 3)
			{
				for (int i = btm; i >= top; i--)
					printEl(arr[i][lt], &prevEl);
				dir = 0;
				lt++;				
			}
		}
		cout << endl;
	}
	return 0;
}