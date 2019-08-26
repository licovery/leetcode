#ifndef N628_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H
#define N628_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H

#include <bits/stdc++.h>
using namespace std;

namespace n628
{

class Solution
{
public:
    int maximumProduct(vector<int> &nums)
    {
        int result = 0;
        if (nums.size() < 3)
        {
            return result;
        }
        sort(nums.begin(), nums.end());

        result = nums[nums.size() - 1];
        int lastTwoProduct = nums[nums.size() - 2] * nums[nums.size() - 3];
        int firstTwoProduct = nums[0] * nums[1];
        result *= max(lastTwoProduct, firstTwoProduct);
        return result;
    }
};

}


#endif // N628_MAXIMUM_PRODUCT_OF_THREE_NUMBERS_H
