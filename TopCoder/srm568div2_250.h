#ifndef SRM568DIV2_250_H
#define SRM568DIV2_250_H

#endif // SRM568DIV2_250_H


#include <iostream>

using namespace std;

class TheSimilarNumbers
{
public:
    int find(int lower, int upper)
    {
        int count=1;
        int prev = lower;

        for (int i = lower+1; i <= upper; i++)
        {
            if(!((i<=10*prev) && (prev<=10*i)))
            {
                count++;
                prev = i;
            }
        }
        return count;
    }
};
