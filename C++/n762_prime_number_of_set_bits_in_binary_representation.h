#ifndef N762_PRIME_NUMBER_OF_SET_BITS_IN_BINARY_REPRESENTATION_H
#define N762_PRIME_NUMBER_OF_SET_BITS_IN_BINARY_REPRESENTATION_H

#include <bits/stdc++.h>
using namespace std;

namespace n762
{

class Solution
{
public:
    int countPrimeSetBits(int L, int R)
    {
        int res = 0;
        for (int i = L; i <= R; i++)
        {
            if (isPrimeNumber(bitset<_bitsOfInt>(i).count()))
            {
                res++;
            }
        }
        return res;
    }
private:
    bool isPrimeNumber(int n)
    {
        int upper = n;
        if (n == 0 || n == 1)
        {
            return false;
        }
        for (int i = 2; i < upper; i++)
        {
            if (n % i == 0)
            {
                return false;
            }
            upper = n / i;
        }
        return true;
    }

    static constexpr int _bitsOfInt = sizeof(int) * 8;

};

}

#endif // N762_PRIME_NUMBER_OF_SET_BITS_IN_BINARY_REPRESENTATION_H
