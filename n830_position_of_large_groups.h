#ifndef N830_POSITION_OF_LARGE_GROUPS_H
#define N830_POSITION_OF_LARGE_GROUPS_H

#include <bits/stdc++.h>
using namespace std;

namespace n830
{

class Solution
{
public:
    vector<vector<int>> largeGroupPositions(string S)
    {
        S += '*'; //结束标志
        vector<vector<int>> res;
        int start = 0;
        for (int i = start + 1; i < S.size(); i++)
        {
            if (S[i] != S[start])

            {
                if (i - start >= LARGE)
                {
                    res.push_back({start, i - 1});
                }
                start = i;
            }
        }
        return res;
    }
private:
    static constexpr int LARGE = 3;
};

}

#endif // N830_POSITION_OF_LARGE_GROUPS_H
