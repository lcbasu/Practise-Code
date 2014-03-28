#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

int main()
{
	int arr[301][301];
	int n;
	scanf("%d", &n);
	for(int i = 1; i <=n; i++)
	{
		for(int j = 1; j <= n; j++)
		{
			int el;
			scanf("%d", &el);
			arr[i][j] = el;
		}
	}
	int q;
	scanf("%d", &q);
	while(q--)
	{
		int x1, y1;
		int x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		set<int> unique;
		for(int i = x1; i <= x2; i++)
		{
			for(int j = y1; j <= y2; j++)
			{
				unique.insert(arr[i][j]);
			}
		}
		cout << unique.size() << endl;
	}
	return 0;
}
