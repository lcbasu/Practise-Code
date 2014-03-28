#ifndef SRM571DIV2_500_H
#define SRM571DIV2_500_H

#endif // SRM571DIV2_500_H


#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class FoxAndMp3Easy
{
public:
    vector<string> playList(int n)
    {
        vector<string> ini_vec;
        for (int i = 1; i <= n; ++i)
        {
            stringstream ss;
            ss << i << ".mp3";
            string temp = ss.str();
            ini_vec.push_back(temp);
        }
        vector<string> final_vec;
        if(n<=50)
        {
            sort(ini_vec.begin(), ini_vec.end());
            final_vec.assign(ini_vec.begin(), ini_vec.end());
        }
        else
        {
            sort(ini_vec.begin(), ini_vec.end());
            final_vec.assign(ini_vec.begin(), ini_vec.begin()+50);
        }
        return final_vec;
    }

};
