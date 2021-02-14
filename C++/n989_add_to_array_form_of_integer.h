#ifndef N989_ADD_TO_ARRAY_FORM_OF_INTEGER_H
#define N989_ADD_TO_ARRAY_FORM_OF_INTEGER_H

#include "leetcode_common.h"

namespace n989
{

class Solution
{
public:
    vector<int> addToArrayForm(const vector<int> &A, int K)
    {
        vector<int> res(A);
        reverse(res.begin(), res.end());

        int i = 0;
        int carry = 0;

        while (K || carry)
        {
            if (i >= res.size())
            {
                res.push_back(0);
            }
            int sum = res[i] + K % 10 + carry;
            res[i] = sum % 10;
            carry = sum / 10;
            i++;
            K /= 10; //0除以10还是0
        }

        reverse(res.begin(), res.end());
        return res;
    }
};

}

#endif // N989_ADD_TO_ARRAY_FORM_OF_INTEGER_H
