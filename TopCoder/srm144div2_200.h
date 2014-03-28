#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Time
{
public:
    string whatTime(int seconds)
    {
        int hour = seconds/3600;
        seconds = seconds%3600;
        int min = seconds/60;
        seconds = seconds%60;
        stringstream ss;
        ss << hour << ":" << min << ":" << seconds;
        string temp = ss.str();
        return temp;
    }

};
