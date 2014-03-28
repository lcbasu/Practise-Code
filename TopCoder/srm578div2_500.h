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

#define absVal(x)	((x)>0 ? (x) : (-(x)))

bool visited[50][50];
int rows, columns, d;
vector<string> f;

class GooseInZooDivTwo
{
public:
    void DFS(int r, int c)
    {
        visited[r][c] = true;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(!visited[i][j] && (absVal(r-i)+ absVal(c-j) <= d) && f[i][j] == 'v')
                    DFS(i, j);
            }
        }
    }
    int count(vector <string> field, int dist)
    {
        for (int i = 0; i < 50; i++)
        {
        	for(int j = 0; j < 50; j++)
        	{
        		visited[i][j] = false;
        	}
        }
        f = field;
        d = dist;
        rows = field.size();
        columns = field[0].size();
        int k = 0;
        for(int i = 0; i < rows; i++)
        {
            for(int j = 0; j < columns; j++)
            {
                if(visited[i][j])
                    continue;
                if(field[i][j] == '.')
                    continue;
                k++;
                DFS(i,j);
            }
        }
        long long int ans = 1;
        for (int i = 0; i < k; ++i)
        {
            ans = (ans*2)%1000000007;
        }
        ans = (ans-1+1000000007)%1000000007;
        return ans;
    }
};
