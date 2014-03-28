#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		string tmpShoe;
		vector<string> shoe;
		for (int i = 0; i < n; i++)
		{
			cin >> tmpShoe;
			shoe.push_back(tmpShoe);
		}
		sort(shoe.begin(), shoe.end());
		int pairs = 0;
		vector<bool> checkBox;
		for (int i = 0; i < n; i++)
		{
			checkBox.push_back(false);
		}
		for (int i = 0; i < n; i++)
		{
			tmpShoe = shoe[i];
			for(int j = i+1; j < n; j++)
			{
				if(tmpShoe[0] != shoe[j][0])
					break;
				else if(((tmpShoe[1] == 'L' && shoe[j][1] == 'R') || (tmpShoe[1] == 'R' && shoe[j][1] == 'L')) && (!checkBox[i] && !checkBox[j]))
				{
					pairs++;
					checkBox[i] = true;
					checkBox[j] = true;
				}
			}
		}
		cout << pairs << endl;
	}
	return 0;
}
