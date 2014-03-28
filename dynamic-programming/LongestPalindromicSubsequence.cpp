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

int cacheMem[100][100];

int longestPalSubSeq(char arr[], int startIndex, int endIndex)
{
	if(cacheMem[startIndex][endIndex] > 0)
		return cacheMem[startIndex][endIndex];

	if(startIndex == endIndex)
		cacheMem[startIndex][endIndex] = 1;
	else if(arr[startIndex] == arr[endIndex] && endIndex == startIndex + 1)
		cacheMem[startIndex][endIndex] = 2;
	else if(arr[startIndex] == arr[endIndex])
		cacheMem[startIndex][endIndex] = longestPalSubSeq(arr, startIndex+1, endIndex-1) + 2;
	else if(arr[startIndex] != arr[endIndex] && endIndex == startIndex + 1)
		cacheMem[startIndex][endIndex] = 1;
	else if(arr[startIndex] != arr[endIndex])
		cacheMem[startIndex][endIndex] = max(longestPalSubSeq(arr, startIndex+1, endIndex), longestPalSubSeq(arr, startIndex, endIndex-1));

	return cacheMem[startIndex][endIndex];
}

int main()
{
	for (int i = 0; i < 100; ++i)
	{
		for(int j = 0; j < 100; j++)
			cacheMem[i][j] = -1;
	}
	char arr[] = {'X','A','B','Y','B','Z','B','A','B','A'};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << longestPalSubSeq(arr, 0, n) << endl;


	return 0;
}