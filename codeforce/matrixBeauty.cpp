#include <algorithm>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <list>
#include <map>
#include <set>
#include <ctype.h>
#include <math.h>
#include <limits>	// numeric_limits<int>::max() similarly for other

using namespace std;

int main()
{
	int t;
	cin >> t;
	if(t == 1)
	{
		int el;
		cin >> el;
		cout << el << endl;
	}
	else
	{
		vector<int> matrixEle;
		int maxNum[4];
		int temp;
		for (int i = 0; i < t; i++)
		{
			cin >> temp;
			matrixEle.push_back(temp);
		}
		sort(matrixEle.begin(), matrixEle.end());
		int len = matrixEle.size();
		long long int sum = matrixEle[len-1];
		for (int i = 1; i <= 4; i++)
		{
			sum = sum + matrixEle[len-i];
		}
		cout << sum << endl;
	}

	return 0;
}