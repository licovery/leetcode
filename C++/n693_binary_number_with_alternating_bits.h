#ifndef N693_BINARY_NUMBER_WITH_ALTERNATING_BITS_H
#define N693_BINARY_NUMBER_WITH_ALTERNATING_BITS_H

#include <bits/stdc++.h>
using namespace std;

namespace n693
{

class Solution
{
public:
    bool hasAlternatingBits(int n)
    {
        if (n <= 0)
        {
            return false;
        }
        int cur = n & 1;
        n = n >> 1;
        while (n)
        {
            if (cur == (n & 1))
            {
                return false;
            }
            n = n >> 1;
            cur = n & 1;
        }
        return true;
    }
};

}


#endif // N693_BINARY_NUMBER_WITH_ALTERNATING_BITS_H
