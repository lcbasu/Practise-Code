#include <iostream>


using namespace std;

int main()
{
	string str;
	cin >> str;
	int n = str.size();
	int m;
	cin >> m;
	while(m--)
	{
		int l, r;
		cin >> l >> r;
		if(l >= 1 && r <= n && l < r)
		{
			int count = 0;

			for (l; l < r; l++)
			{
				if(str[l-1] == str[l])
					count++;
			}
			cout << count << endl;			
		}
	}
	return 0;
}