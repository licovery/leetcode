#ifndef N821_SHORTEST_DISTANCE_TO_A_CHARACTOR_H
#define N821_SHORTEST_DISTANCE_TO_A_CHARACTOR_H

#include "bits/stdc++.h"
using namespace std;

namespace n821
{

class Solution
{
public:
    vector<int> shortestToChar(string S, char C)
    {
        vector<int> res(S.size(), 0);
        vector<int> CIndex;
        CIndex.push_back(-MAX_STR_LEN);
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                CIndex.push_back(i);
            }
        }
        CIndex.push_back(MAX_STR_LEN * 2);

        int index = 1;
        for (int i = 0; i < S.size(); i++)
        {
            if (S[i] == C)
            {
                res[i] = 0;
                index++;
            }
            else
            {
                res[i] = min(i - CIndex[index - 1], CIndex[index] - i);
            }
        }
        return res;
    }
private:
    static constexpr int MAX_STR_LEN = 10000;
};
}

#endif // N821_SHORTEST_DISTANCE_TO_A_CHARACTOR_H
