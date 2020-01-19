#ifndef N784_LETTER_CASE_PERMUTATION_H
#define N784_LETTER_CASE_PERMUTATION_H

#include <bits/stdc++.h>
using namespace std;

namespace n784
{

class Solution
{
public:
    vector<string> letterCasePermutation(string S)
    {
        vector<string> res;
        dfs(S, res, "", 0);
        return res;
    }

    void dfs(const string &s, vector<string> &res, string curStr, int curLen)
    {
        if (curLen >= s.size())
        {
            res.push_back(curStr);
            return;
        }

        char curchar = s[curLen];
        dfs(s, res, curStr + curchar, curLen + 1);

        if (isalpha(curchar))
        {
            if (isupper(curchar))
            {
                curchar = tolower(curchar);
            }
            else
            {
                curchar = toupper(curchar);
            }
            dfs(s, res, curStr + curchar, curLen + 1);
        }
    }
};

}

#endif // N784_LETTER_CASE_PERMUTATION_H
