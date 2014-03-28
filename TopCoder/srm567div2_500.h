#ifndef SRM567DIV2_500_H
#define SRM567DIV2_500_H

#endif // SRM567DIV2_500_H


#include <iostream>
#include <cmath>

using namespace std;

class TheSquareRootDilemma
{
public:
    int countPairs(int N, int M)
    {
        int count = 0;
        for (int i = 1; i <= N; i++)
        {
            for(int j = 1; j <= M; j++)
            {
                double ssr = (i + j + 2*sqrt(i*j));
                int is_integer = (int)(ssr);
                if(is_integer == ssr)
                    count++;
            }
        }
        return count;
    }
};
