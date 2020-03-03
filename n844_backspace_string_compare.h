#ifndef N844_BACKSPACE_STRING_COMPARE_H
#define N844_BACKSPACE_STRING_COMPARE_H

#include <bits/stdc++.h>
using namespace std;

namespace n844
{

class Solution
{
public:
    bool backspaceCompare(string S, string T)
    {
        return stringToText(S) == stringToText(T);
    }
private:
    stack<char> stringToText(const string &s)
    {
        stack<char> res;
        for (char c : s)
        {
            if (c == '#')
            {
                if (res.size() > 0)
                {
                    res.pop();
                }
            }
            else
            {
                res.push(c);
            }
        }
        return res;
    }
};

}

#endif // N844_BACKSPACE_STRING_COMPARE_H
