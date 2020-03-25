#ifndef N905_SORT_ARRAY_BY_PARITY_H
#define N905_SORT_ARRAY_BY_PARITY_H

#include <bits/stdc++.h>
using namespace std;

namespace n905
{

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &A)
    {
        int even = 0;
        int odd = A.size() - 1;

        while (1)
        {
            while (even < A.size() && isEven(A[even]))
            {
                even++;
            }
            while (odd >= 0 && isOdd(A[odd]))
            {
                odd--;
            }

            if (even < odd)
            {
                swap(A[even], A[odd]);
            }
            else
            {
                break;
            }
        }
        return A;
    }
private:
    bool isEven(int n)
    {
        return (n & 0x01) == 0;
    }

    bool isOdd(int n)
    {
        return !isEven(n);
    }
};

}

#endif // N905_SORT_ARRAY_BY_PARITY_H
