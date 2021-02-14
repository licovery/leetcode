#ifndef N917_REVERSE_ONLY_LETTERS_H
#define N917_REVERSE_ONLY_LETTERS_H

#include "leetcode_common.h"

namespace n917
{

class Solution
{
public:
    string reverseOnlyLetters(string S)
    {
        int left = 0;
        int right = S.size() - 1;

        while (left < right)
        {
            while (left < S.size() && !isalpha(S[left]))
            {
                left++;
            }
            while (right >= 0 && !isalpha(S[right]))
            {
                right--;
            }
            if (left < right)
            {
                swap(S[left++], S[right--]);
            }
        }
        return S;
    }
};

}

#endif // N917_REVERSE_ONLY_LETTERS_H
