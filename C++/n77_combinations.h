#ifndef N77_COMBINATIONS_H
#define N77_COMBINATIONS_H

#include <bits/stdc++.h>
using namespace std;

namespace n77
{

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<int> numbers(n, 0);
        for (int i = 0; i < numbers.size(); i++)
        {
            numbers[i] = i + 1;
        }

        vector<vector<int>> res;
        dfs(res, numbers, 0, k);
        return res;
    }
private:
    void dfs(vector<vector<int>> &res, vector<int> &numbers, int step, int k)
    {
        if (step == k)
        {
            res.push_back(vector<int> (numbers.begin(), numbers.begin() + k));
        }

        for (int i = step; i < numbers.size(); i++)
        {
            swap(numbers[step], numbers[i]);
            if (step == 0 || numbers[step] > numbers[step - 1])
            {
                dfs(res, numbers, step + 1, k);
            }
            swap(numbers[step], numbers[i]);
        }
    }
};

}

#endif // N77_COMBINATIONS_H
