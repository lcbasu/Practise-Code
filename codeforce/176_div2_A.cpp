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

using namespace std;

int main()
{
	char inArr[4][4];
	for (int i = 0; i < 4; ++i)
	{
		for(int j = 0; j < 4; j++)
			cin >> inArr[i][j];
	}

	bool found = false;
	for (int i = 0; i < 3; ++i)
	{
		for(int j = 0; j < 3; j++)
		{
			int totalBlack = 0;
			int totalWhite = 0;
			if(inArr[i][j] == '#')
				totalBlack++;
			if(inArr[i][j+1] == '#')
				totalBlack++;
			if(inArr[i+1][j] == '#')
				totalBlack++;
			if(inArr[i+1][j+1] == '#')
				totalBlack++;

			if(inArr[i][j] == '.')
				totalWhite++;
			if(inArr[i][j+1] == '.')
				totalWhite++;
			if(inArr[i+1][j] == '.')
				totalWhite++;
			if(inArr[i+1][j+1] == '.')
				totalWhite++;			
			if(totalBlack >= 3 || totalWhite >=3)	
			{
				found = true;
				break;
			}
		}
		if(found)
			break;
	}
	if(found)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
	return 0;
}