#ifndef N_392_IS_SUBSEQUENCE_H
#define N_392_IS_SUBSEQUENCE_H

#include <bits/stdc++.h>
#include <functional>

using namespace std;

namespace n392
{

class Solution
{
public:
    bool isSubsequence(string s, string t)
    {
        for (int i = 0; i < t.size(); ++i)
        {
            auto it = charIndexs.find(t[i]);
            if (it == charIndexs.end())
            {
                charIndexs[t[i]] = vector<int> {i};
            }
            else
            {
                it->second.push_back(i);
            }
        }
        return matchSubStr(s, 0, 0);
    }
private:
    bool matchSubStr(const string &subStr, int match, int curIndex)
    {
        if (match == subStr.size())
        {
            return true;
        }

        char ch = subStr[match];
        auto it = charIndexs.find(ch);
        if (it == charIndexs.end())
        {
            return false;
        }

        const vector<int> &index = it->second;
        auto ge = [curIndex] (int i)
        {
            return i >= curIndex;
        };
        auto firstIndex = find_if(index.begin(), index.end(), ge);
        for (; firstIndex != index.end(); firstIndex++)
        {
            if (matchSubStr(subStr, match + 1, *firstIndex + 1))
            {
                return true;
            }
        }
        return false;
    }
    map<char, vector<int>> charIndexs;
};


}

#endif // N_392_IS_SUBSEQUENCE_H
