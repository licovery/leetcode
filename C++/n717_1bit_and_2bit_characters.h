#ifndef N717_1BIT_AND_2BIT_CHARACTERS_H
#define N717_1BIT_AND_2BIT_CHARACTERS_H

#include <bits/stdc++.h>
using namespace std;

namespace n717
{

class Solution
{
    enum STATUS
    {
        INIT,
        TWOBIT,
    };
public:
    bool isOneBitCharacter(vector<int> &bits)
    {
        STATUS status = INIT;
        for (int i = 0; i < bits.size() - 1; i++)
        {
            switch (status)
            {
                case INIT:
                {
                    if (bits[i] == 1) status = TWOBIT;
                    break;
                }
                case TWOBIT:
                {
                    status = INIT;
                }
            }

        }
        return status != TWOBIT;
    }
};

}

#endif // N717_1BIT_AND_2BIT_CHARACTERS_H
