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

class BusinessTasks
{
public:

	int getIndex(int totalSize, int n)
	{
		if(totalSize==1)
			return 1;
		return ((getIndex(totalSize-1, n) + n-1)%totalSize + 1);
	}

    string getTask(vector <string> list, int n)
    {
        return list[getIndex(list.size(), n) - 1];
    }
};
