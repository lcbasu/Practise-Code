#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <set>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<int> id;
		vector<string> user;
		int tmpId;
		string tmpName;
		for (int i = 0; i < n; ++i)
		{
			cin >> tmpId >> tmpName;
			id.push_back(tmpId);
			user.push_back(tmpName);
		}
		set<string> uniqueUser;

		for (int i = 0; i < n; ++i)
		{
			uniqueUser.insert(user[i]);
		}
		vector<int> score;
		set<string>::iterator it;		
		for(it = uniqueUser.begin(); it != uniqueUser.end();it++)
		{
			int countFreq = 0;
			int countTime = 0;
			string tmp = *it;
			for(int j = 0; j < n; j++)
			{
				if(tmp == user[j])
				{
					countTime = countTime + j;
					countFreq++;
				}
			}
			score.push_back(countFreq+countTime);
		}
		int maxIndex = 0;
		int i=0;
		int max = 0;
		for (it = uniqueUser.begin(); it != uniqueUser.end();it++, i++)
		{
			if(score[i] > max)
			{
				max = score[i];
				maxIndex = i;
			}
		}
		for (it = uniqueUser.begin(); it != uniqueUser.end();it++, i++)
		{
			if(i == maxIndex)
			{
				cout <<  *it << endl;
				break;
			}
		}		
	}
	return 0;
}
