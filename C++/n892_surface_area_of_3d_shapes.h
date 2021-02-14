#ifndef N892_SURFACE_AREA_OF_3D_SHAPES_H
#define N892_SURFACE_AREA_OF_3D_SHAPES_H

#include <bits/stdc++.h>
using namespace std;

namespace n892
{

class Solution
{
public:
    // 先计算单个tower面积，再减去重叠部分
    int surfaceArea(vector<vector<int>> &grid)
    {
        int res = 0;
        int directionRow[4] =     {0, 1, 0, -1}; //north south east west
        int direactionColumn[4] = {1, 0, -1, 0};

        for (int i = 0; i < grid.size(); i++)
        {
            for (int j = 0; j < grid[i].size(); j++)
            {
                if (grid[i][j] == 0)
                {
                    continue;
                }

                res += areaOfTower(grid[i][j]);

                for (int d = 0;  d < 4; d++)
                {
                    int r = i + directionRow[d];
                    int c = j + direactionColumn[d];
                    if (0 <= r && r < grid.size() && 0 <= c && c < grid[i].size())
                    {
                        res -= min(grid[i][j], grid[r][c]);
                    }
                }
            }
        }
        return res;
    }
private:
    int areaOfTower(int high)
    {
        if (high <= 0)
        {
            return 0;
        }
        return 4 * high + 2;
    }
};

}

#endif // N892_SURFACE_AREA_OF_3D_SHAPES_H
