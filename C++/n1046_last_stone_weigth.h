#include "leetcode_common.h"

namespace n1046
{

class Solution
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        while (stones.size() > 1)
        {
            sort(stones.begin(), stones.end());
            int last = stones.size() - 1;
            stones[last - 1] = stones[last] - stones[last - 1];
            stones.pop_back();
            if (stones[last - 1] == 0)
            {
                stones.pop_back();
            }
        }

        if (stones.size() == 0)
        {
            return 0;
        }
        return stones[0];
    }
};

class Solution2
{
public:
    int lastStoneWeight(vector<int> &stones)
    {
        priority_queue<int> pq(stones.begin(), stones.end());
        while (pq.size() > 1)
        {
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if (y != x)
            {
                pq.push(y - x);
            }
        }
        if (pq.empty())
        {
            return 0;
        }
        return pq.top();
    }
};

} // namespace n1046