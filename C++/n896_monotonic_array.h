#ifndef N896_MONOTONIC_ARRAY_H
#define N896_MONOTONIC_ARRAY_H

#include "bits/stdc++.h"
using namespace std;

namespace n896
{

class Solution
{
public:
    bool isMonotonic(vector<int> &A)
    {
        if (A.size() == 0)
        {
            return true;
        }
        int cmp = 0;
        for (int i = 0; i + 1 < A.size(); i++)
        {
            if (A[i] == A[i + 1])
            {
                continue;
            }
            if (A[i] < A[i + 1])
            {
                if (cmp == 0)
                {
                    cmp = 1;
                }
                else if (cmp != 1)
                {
                    return false;
                }
            }
            else
            {
                if (cmp == 0)
                {
                    cmp = -1;
                }
                else if (cmp != -1)
                {
                    return false;
                }
            }
        }
        return true;
    }
};

}

#endif // N896_MONOTONIC_ARRAY_H
