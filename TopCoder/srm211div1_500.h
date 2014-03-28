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

bool visited[400][600];  //FALSE - not visited, TRUE - visited

struct Coordinate
{
    int x;
    int y;
};

Coordinate *newCoordinate(int x, int y)
{
    Coordinate *c = new Coordinate();
    c->x = x;
    c->y = y;
    return c;
}

class grafixMask
{
public:
    vector <int> sortedAreas(vector <string> rectangles)
    {
        for (int i = 0; i < 400; ++i)
        {
            for(int j = 0; j < 600; j++)
                visited[i][j] = false;
        }
        int x1,y1;
        int x2,y2;
        for (int i = 0; i < rectangles.size(); ++i)
        {
            string rec = rectangles[i];
            stringstream ss;
            ss << rec;
            ss >> y1 >> x1 >> y2 >> x2;
            for (int i = y1; i <= y2; ++i)
            {
                for(int j = x1; j <= x2; j++)
                    visited[i][j] = true;
            }
        }
        vector<int> result;
        for (int i = 0; i < 400; ++i)
        {
            for(int j = 0; j < 600; j++)
            {
                if(!visited[i][j])
                {
                    int area = fillColour(j, i);
                    if(area > 0)
                        result.push_back(area);
                }
            }
        }
        sort(result.begin(), result.end());
        return result;
    }
    int fillColour(int x, int y)
    {
        stack<Coordinate *> st;
        Coordinate *tmp = newCoordinate(x, y);
        st.push(tmp);
        int area = 0;
        while(!st.empty())
        {
            Coordinate *top = st.top();
            st.pop();
            if(top->x < 0 || top->x >= 600 || top->y < 0 || top->y >= 400 || visited[top->y][top->x])
                continue;

            visited[top->y][top->x] = true;
            area++;

            st.push(newCoordinate(top->x+1, top->y));
            st.push(newCoordinate(top->x-1, top->y));
            st.push(newCoordinate(top->x, top->y+1));
            st.push(newCoordinate(top->x, top->y-1));
        }
        return area;
    }
};
