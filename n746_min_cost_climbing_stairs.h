#ifndef N746_MIN_COST_CLIMBING_STAIRS_H
#define N746_MIN_COST_CLIMBING_STAIRS_H

#include <bits/stdc++.h>
using namespace std;

namespace n746
{

class Solution
{
public:
    int minCostClimbingStairs(vector<int> &cost)
    {
        vector<int> dp(cost.size() + 1, 0);

        for (int i = 2; i < dp.size(); i++)
        {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[dp.size() - 1];
    }
};

}



#endif // N746_MIN_COST_CLIMBING_STAIRS_H
