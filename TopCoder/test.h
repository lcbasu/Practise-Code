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

using namespace std;

class DiamondHunt
{
public:
    int countDiamonds(string mine);
};

int DiamondHunt::countDiamonds(string mine)
{
    int total_diamonds = 0;
    for(int i = 0; i < mine.size(); i++)
    {
        if((i+1)<mine.size())
        {
            if(mine[i] == '<' && mine[i+1] == '>')
            {
                mine.erase(i,2);
                total_diamonds = total_diamonds + 1;
                i = -1;
            }
        }
    }
    return total_diamonds;
}