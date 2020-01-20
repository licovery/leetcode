#ifndef N796_ROTATE_STRING_H
#define N796_ROTATE_STRING_H

#include <bits/stdc++.h>
using namespace std;

namespace n796
{

class Solution
{
public:
    bool rotateString(string A, string B)
    {
        if (A.size() != B.size()) return false;
        bool res = true;
        for (int i = 0; i < A.size(); i++)
        {
            res = true;
            for (int j = 0; j < A.size(); j++)
            {
                if (A[(j + i) % A.size()] != B[j])
                {
                    res = false;
                    break;
                }
            }
            if (res) break;
        }
        return res;
    }
};

}

#endif // N796_ROTATE_STRING_H
