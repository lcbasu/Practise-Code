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

class ThrowTheBall
{
public:
    int timesThrown(int N, int M, int L)
    {
        int totalPass = 0;
        int totalReceiving[N];
        int playerIndex=0;
        for (int i = 0; i < N; ++i)
        {
        	totalReceiving[i] = 0;
        }
        totalReceiving[playerIndex] = 1;
        while(true)
        {
        	if(totalReceiving[playerIndex] == M)
        		break;
        	if(totalReceiving[playerIndex]%2 ==0)
        	{
        		playerIndex = (playerIndex + L)%N;
        		totalReceiving[playerIndex]++;
        	}
        	else
        	{
        		playerIndex = (playerIndex - L + N)%N;
        		totalReceiving[playerIndex]++;
        	}
        	totalPass++;
        }
        return totalPass;
    }
};
