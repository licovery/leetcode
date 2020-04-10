#include "leetcode_common.h"

namespace n1351
{

class Solution
{
public:
    int countNegatives(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }

        int row = grid.size();
        int column = grid[0].size();

        int negative = 0;

        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < column; j++) // 另外一种思路是这里使用二分查找，找出第一个负数
            {
                if (grid[i][j] < 0)
                {
                    negative += (column - j) * (row - i);
                    column = j;
                    break;
                }
            }
        }
        return negative;
    }
};

} // namespace n1351