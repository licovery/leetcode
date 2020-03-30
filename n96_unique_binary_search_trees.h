#ifndef N96_UNIQUE_BINARY_SEARCH_TREES_H
#define N96_UNIQUE_BINARY_SEARCH_TREES_H

#include "leetcode_common.h"

namespace n96
{

class Solution
{
public:
    int numTrees(int n)
    {
        vector<int> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                dp[i] += dp[j] * dp[i - 1 - j];
            }
        }
        return dp[n];
    }
};

}

#endif // N96_UNIQUE_BINARY_SEARCH_TREES_H
