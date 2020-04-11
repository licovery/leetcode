#include "leetcode_common.h"

namespace n1380
{
    
class Solution
{
public:
    vector<int> luckyNumbers(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
        {
            return vector<int>();
        }
        set<int> minInRow;
        for (int i = 0; i < matrix.size(); i++)
        {
            int n = INT_MAX;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                n = min(n, matrix[i][j]);
            }
            minInRow.insert(n);
        }

        set<int> maxInCol;
        for (int j = 0; j < matrix[0].size(); j++)
        {
            int n = INT_MIN;
            for (int i = 0; i < matrix.size(); i++)
            {
                n = max(n, matrix[i][j]);
            }
            maxInCol.insert(n);
        }

        vector<int> res(min(minInRow.size(), maxInCol.size()));
        auto it = set_intersection(minInRow.begin(), minInRow.end(), maxInCol.begin(), maxInCol.end(), res.begin());
        return vector<int>(res.begin(), it);
    }
};

} // namespace n1380