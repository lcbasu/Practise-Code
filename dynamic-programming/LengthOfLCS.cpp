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

int lengthOfLCS(int arr[], int n)
{
	int longestSum[n];
	longestSum[0] = 1;
	for (int i = 0; i < n; i++)
	{
		int maxLength = numeric_limits<int>::min();
		bool noSuchJExist = true;
		for(int j = 0; j < i; j++)
		{
			if(arr[i] > arr[j])
			{
				noSuchJExist = false;
				if(longestSum[j] > maxLength)	
					maxLength = longestSum[j];
			}
		}
		if(noSuchJExist)
			longestSum[i] = 1;
		else
			longestSum[i] = 1 + maxLength;
	}
	return longestSum[n-1];
}

int main()
{
	int arr[] = {10, 22, 9, 33, 21, 50, 41, 60, 80};
	int n = sizeof(arr)/sizeof(arr[0]);
	cout << lengthOfLCS(arr, n) << endl;
	return 0;
}
