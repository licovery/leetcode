#ifndef N860_LEMONADE_CHANGE_H
#define N860_LEMONADE_CHANGE_H

#include <bits/stdc++.h>
using namespace std;

namespace n860
{

class Solution
{
public:
    bool lemonadeChange(vector<int> &bills)
    {
        int nfive = 0;
        int nten = 0;

        for (int i = 0; i < bills.size(); i++)
        {
            // get five, not give back
            if (bills[i] == 5)
            {
                nfive++;
            }
            // get ten, give back five
            else if (bills[i] == 10)
            {
                nten++;
                nfive--;
            }
            // get twenty, give back fifteen
            else if (bills[i] == 20)
            {
                if (nten) // fitten = ten + five
                {
                    nten--;
                    nfive--;
                }
                else // fifteen = 3  * five
                {
                    nfive -= 3;
                }
            }


            if (nfive < 0 || nten < 0)
            {
                return false;
            }
        }

        return true;
    }
};

}

#endif // N860_LEMONADE_CHANGE_H
