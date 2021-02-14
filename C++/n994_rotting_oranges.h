#include "leetcode_common.h"

namespace n994
{

constexpr int DIRECTION[4][2] = {{0, 1},
                                 {0, -1},
                                 {1, 0},
                                 {-1, 0}};

class Solution
{
public:
    int orangesRotting(vector<vector<int>> &grid)
    {
        if (grid.size() == 0)
        {
            return 0;
        }

        queue<pair<int, int>> rotten;
        int minute = 0;
        int freshOrange = 0;
        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[0].size(); j++)
            {
                if (grid[i][j] == ROTTEN)
                {
                    rotten.push({i, j});
                }
                else if (grid[i][j] == FRESH)
                {
                    freshOrange++;
                }
            }
        }

        while (freshOrange && !rotten.empty())
        {
            int curRotten = rotten.size(); //当前一分钟已经腐烂的橙子个数
            while (curRotten--)
            {
                auto tmp = rotten.front();
                rotten.pop();
                grid[tmp.first][tmp.second] = EMPTY; //清空已经腐烂的橘子

                for (int i = 0; i < 4; i++)
                {
                    int r = tmp.first + DIRECTION[i][0];
                    int c = tmp.second + DIRECTION[i][1];

                    if (r < 0 || r >= grid.size() || c < 0 || c >= grid[0].size())
                    {
                        continue;
                    }

                    if (grid[r][c] == FRESH)
                    {
                        rotten.push({r, c});
                        grid[r][c] = ROTTEN;
                        freshOrange--;
                    }
                }
            }

            minute++;
        }

        if (freshOrange)
        {
            return -1;
        }
        return minute;
    }

private:
    static constexpr int EMPTY = 0;
    static constexpr int FRESH = 1;
    static constexpr int ROTTEN = 2;
};

} // namespace n994