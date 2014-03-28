#include <iostream>

using namespace std;


//0 -> a, 1 -> b, 2 -> c, 3 -> d 
bool isInterSecting(int first[], int second[])
{
	if(first[2] < second[0] || second[2] < first[0] || first[3] < second[1] || second[3] < first[1])
		return false;
	return true;
}


int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int first[4];
		int second[4];
		for (int i = 0; i < 4; ++i)
		{
			cin >> first[i];
		}
		for (int i = 0; i < 4; ++i)
		{
			cin >> second[i];
		}
		if(isInterSecting(first, second))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}
	return 0;
}