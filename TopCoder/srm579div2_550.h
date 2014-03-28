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
#include <limits>   // numeric_limits<int>::max() similarly for other

using namespace std;

class CLASS_NAME
{
public:
    int minPresses(vector <string> lines)
    {
        int cost = lines[0].size() + 1;
        for (int i = 1 ; i < lines.size(); i++) {
            int icost = 1000000000; //A large number
            
            
            for (int j = 0; j < i; j++) {
                int k = 0;
                while (k < lines[i].size() && k < lines[j].size() ) {
                    if (lines[i][k] == lines[j][k]) {
                        k++;
                    } else {
                        break;
                    }
                }
                // k is the length of the largest common prefix between lines[i] and lines[j]
                int ijcost = 2 + (lines[i].size() - k) + 1;
                if (j == i-1 && k==lines[j].size()) {
                    // lines[j] is a prefix of lines[i], then there is a cost to continue
                    // typing lines[i] equal to (lines[i].size() - k) + 1, same as subtracting
                    // 2 from ijcost:
                    ijcost -= 2;
                }
                icost = std::min<int>(icost, ijcost);

            }
            cost += icost;
        }
        return cost;
    }    
};


