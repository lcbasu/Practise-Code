#include <iostream>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		string itemCat;
		cin >> itemCat;
		int price[26];
		int itemFreq[26];
		for (int i = 0; i < 26; i++)
		{
			cin >> price[i];
			itemFreq[i] = 0;
		}
		int catIndex;
		for (int i = 0; i < itemCat.size(); i++)
		{
			catIndex= 'A' - itemCat[i];
			itemFreq[catIndex]++;
		}
		int amtPayable = 0;
		for (int i = 0; i < 26; i++)
		{
			if(itemFreq[i] > 0)
			{
				amtPayable = amtPayable + ((itemFreq[i]/3)*2 + itemFreq[i]%3)*price[i];
				cout << amtPayable << endl;
			}
		}
		cout << amtPayable << endl;

	}
	return 0;
}