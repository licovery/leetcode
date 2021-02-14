#ifndef N11_CONTAINER_WITH_MOST_WATER_H
#define N11_CONTAINER_WITH_MOST_WATER_H

#include "leetcode_common.h"

class Solution
{
public:
    int maxArea(vector<int> &height)
    {
        int res = 0;
        int i = 0;
        int j = height.size() - 1;
        while (i < j)
        {
            res = max(res, min(height[i], height[j]) * (j - i));
            // 总是移动较短的
            if (height[i] < height[j])
            {
                i++;
            }
            else
            {
                j--;
            }
        }
        return res;
    }

    int maxArea1(vector<int> &height)
    {
        int res = 0;
        for (int i = 0; i < height.size(); i++)
        {
            for (int j = i + 1; j < height.size(); j++)
            {
                int curArea = min(height[i], height[j]) * (j - i);
                res = max(res, curArea);
            }
        }
        return res;
    }
};

#endif // N11_CONTAINER_WITH_MOST_WATER_H
