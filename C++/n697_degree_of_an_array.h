#ifndef N697_DEGREE_OF_AN_ARRAY_H
#define N697_DEGREE_OF_AN_ARRAY_H

#include <bits/stdc++.h>
using namespace std;

namespace n697
{

class Solution
{
public:
    int findShortestSubArray(vector<int> &nums)
    {
        int frequency[MAX_NUM] = {0};
        int first[MAX_NUM] = {0};
        int last[MAX_NUM] = {0};
        int degree = 0;

        for (int i = 0; i < nums.size(); i++)
        {

            if (frequency[nums[i]] == 0)
            {
                first[nums[i]] = i;
            }
            degree = max(degree, ++frequency[nums[i]]);
            last[nums[i]] = i;
        }

        int res = MAX_NUM;
        for (int i = 0; i < MAX_NUM; i++)
        {
            if (frequency[i] == degree)
            {
                res = min(res, last[i] - first[i] + 1);
            }
        }
        return res;
    }
private:
    static constexpr int MAX_NUM = 50000;
};

}

#endif // N697_DEGREE_OF_AN_ARRAY_H
