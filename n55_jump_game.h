#include "leetcode_common.h"

namespace n55
{

class Solution
{
public:
    bool canJump(vector<int> &nums)
    {
        return canJump(nums, nums.size() - 1);
    }

private:
    bool canJump(const vector<int> &num, int target)
    {
        if (target == 0)
        {
            return true;
        }
        else if (target >= num.size())
        {
            return false;
        }

        for (int i = target - 1; i >= 0; i--)
        {
            if (num[i] >= target - i)
            {
                return canJump(num, target - 1);
            }
        }
        return false;
    }
};

class Solution2
{
public:
    bool canJump(const vector<int> &nums)
    {
        int reach = 0;
        for (int i = 0; i < nums.size() && i <= reach; i++)
        {
            reach = max(nums[i] + i, reach);
            if (reach >= nums.size() - 1)
            {
                return true;
            }
        }
        return false;
    }
};

} // namespace n55