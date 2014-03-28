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

class ValueAddedTax
{
public:
    double calculateFinalPrice(string product, int price, vector<string> food)
    {
        bool isFood = false;
        for (int i = 0; i < food.size(); ++i)
        {
        	if(product.compare(food[i]) == 0)
        	{
        		isFood = true;
        		break;
        	}
        }
        if(isFood)
        	return static_cast<double>(1.10*price);
        else
        	return static_cast<double>(1.18*price);
    }
};
