#include "srm144div2_200.h"
#include "srm567div2_250.h"
#include "srm567div2_500.h"
#include "srm568div2_250.h"
#include "srm571div2_500.h"
#include "srm345div2_250.h"
#include "srm346div2_250.h"
#include "srm347div2_250.h"
#include "srm211div1_500.h"

using namespace std;


int main()
{
    /*



    //SRM-144-2-200
    Time obj1;
    cout << obj1.whatTime(3661) << endl;

    //SRM-567-2-250
    NinjaTurtles obj2;
    cout << obj2.countOpponents(5,4) << endl;

    //SRM-567-2-500
    TheSquareRootDilemma obj3;
    cout << obj3.countPairs(100,100) << endl;

    //srm-568-2-250
    TheSimilarNumbers obj4;
    cout << obj4.find(1,1000000) << endl;

    //SRM-571-2-500
    vector<string> v;
    FoxAndMp3Easy obj5;
    v = obj5.playList(109);
    for (int i = 0; i < 50; ++i)
    {
        cout << v[i] << " ";
    }





    //SRM-345-2-250
    Trekking obj6;
    string s = "^^....^^^...";
    vector<string> v2;
    v2.push_back("CwwCwwCwwCww");
    v2.push_back("wwwCwCwwwCww");
    v2.push_back("wwwwCwwwwCww");
    cout << obj6.findCamps(s,v2) << endl;


    DiamondHunt obj7;
    cout << obj7.countDiamonds("><<><><<>>>><<>><<><<>><<<>>>>>><<<") << endl;




    //SRM-347-2-250
    CarBuyer obj8;
    vector<string> v;
    v.push_back("10000 50 50");
    v.push_back("12000 500 10");
    v.push_back("15000 100 65");
    v.push_back("20000 20 80");
    v.push_back("25000 10 90");

    cout << obj8.lowestCost(v ,8 , 25000, 10) << endl;


    ShorterSuperSum obj9;
    cout << obj9.calculate(1,3) << endl;


    */

    vector<string> v;
    v.push_back("0 292 399 307");

    grafixMask obj;
    vector<int> result = obj.sortedAreas(v);
    for (int i = 0; i < result; ++i)
    {
        cout << result[i] << endl;
    }

    return 0;
}
