#ifndef N682_BASEBALL_GAME_H
#define N682_BASEBALL_GAME_H

#include <bits/stdc++.h>
using namespace std;

namespace n682
{

class Solution
{
public:
    int calPoints(vector<string> &ops)
    {
        vector<int> score;
        for (auto op : ops)
        {
            if (op == "+")
            {
                score.push_back(score[score.size() - 1] + score[score.size() - 2]);
            }
            else if (op == "D")
            {
                score.push_back(score[score.size() - 1]);
            }
            else if (op == "C")
            {
                score.pop_back();
            }
            else
            {
                score.push_back(stoi(op));
            }
        }
        return accumulate(score.begin(), score.end(), 0);
    }
};

}

#endif // N682_BASEBALL_GAME_H
