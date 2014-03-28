#ifndef SRM567DIV2_250_H
#define SRM567DIV2_250_H

#endif // SRM567DIV2_250_H


#include <iostream>

using namespace std;

class NinjaTurtles
{
public:
    int countOpponents(int P, int K)
    {
        int N=1;
        while(true)
        {
            int t_pizza = ((N/K)*3) + (N/3);
            if(t_pizza == P)
                return N;
            else if(t_pizza > P)
                return -1;
            N++;
        }
    }
};

