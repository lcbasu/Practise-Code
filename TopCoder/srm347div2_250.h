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
#include <limits>

using namespace std;

class CarBuyer
{
public:
    double lowestCost(vector <string> cars, int fuelPrice, int annualDistance, int years)
    {
        double carCost = numeric_limits<double>::max();
        for (int i = 0; i < cars.size(); ++i)
        {
            int purchaseCost, tax, fuelEff;
            stringstream ss;
            ss << cars[i];
            ss >> purchaseCost >> tax >> fuelEff;
            carCost = min(carCost, static_cast<double>(purchaseCost + tax*years + (fuelPrice*annualDistance*years)/fuelPrice));
        }
        return carCost;
    }
};