#include "leetcode_common.h"

namespace n1304
{

class Solution
{
public:
    vector<int> sumZero(int n)
    {
        vector<int> res;
        int group = n / 2;
        for (int i = 1; i <= group; i++)
        {
            res.push_back(i);
            res.push_back(-i);
        }

        if (n % 2 != 0)
        {
            res.push_back(0);
        }
        return res;
    }
};

} // namespace n1304