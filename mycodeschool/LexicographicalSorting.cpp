#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		vector<string> sentence;
		string tmp;
		for (int i = 0; i < n; ++i)
		{
			cin >> tmp;
			sentence.push_back(tmp);
		}
		sort(sentence.begin(), sentence.end());
		for (int i = 0; i < n; ++i)
		{
			if(sentence.size()-1 == i)
				cout << sentence[i];
			else
				cout << sentence[i] << " ";
		}
		cout << endl;
	}
}