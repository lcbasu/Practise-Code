#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>
#include <set>
#include <map>

using namespace std;

struct Node
{
	int pID;
	string username;
};

Node *logTable;



int main()
{
	int t;
	cin >> t;
	while(t--)
	{
		int n;
		cin >> n;
		logTable = new Node[n];

		map<string, int> noOfProblemsSolved;

		map<string, int>::iterator it;
		int max = 0;
		string maxUser;
		for (int i = 0; i < n; i++)
		{
			cin >> logTable[i].pID >> logTable[i].username;

			it = noOfProblemsSolved.find(logTable[i].username);
			if(it == noOfProblemsSolved.end())
				noOfProblemsSolved[logTable[i].username] = 1;
			else
				noOfProblemsSolved[logTable[i].username] = noOfProblemsSolved[logTable[i].username] + 1;
			if(noOfProblemsSolved[logTable[i].username] > max)
			{
				max = noOfProblemsSolved[logTable[i].username];
				maxUser = logTable[i].username;
			}
		}
		cout << maxUser << endl;

	}
	return 0;
}
