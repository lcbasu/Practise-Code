#include <iostream>
#include <cstring>
#include <map>

using namespace std;

int main()
{
	int T;
	cin >> T;
	string S[T];
	for (int i = 0; i < T; i++)
	{
		cin >> S[i];
	}


	for(int j=0; j<T; j++)
	{
		int str_leng = S[j].length();
		int count = 0;

		map<char, char> str_map;
		map<char, char>::iterator it;

		for(int k=0; k<str_leng; k++)
		{
			it = str_map.find(S[j][k]);

			if(it->second == S[j][k])
			{
				str_map.erase(it);
			}
			else
			{
				str_map[S[j][k]] = S[j][k];
				count++;
			}
		}
		cout << count << endl;
	}

	return 0;
}