#ifndef N3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
#define N3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H

#include "bits/stdc++.h"
using namespace std;


namespace n3
{

class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        int res = 0;
        vector<int> charIndex(256, -1); //字符hash表，values是字符在字符串s中的位置
        int begin = 0;
        int end = 0;
        while (end < s.size())
        {
            if (charIndex[s[end]] == -1)
            {
                charIndex[s[end]] = end;
            }
            else
            {
                // 遇到重复字符，把重复字符前面的都去掉
                for (int i = begin; i < charIndex[s[end]]; i++)
                {
                    charIndex[s[i]] = -1;
                }
                begin = charIndex[s[end]] + 1;
                charIndex[s[end]] = end;
            }
            end++;
            res = max(res, end - begin);
        }
        return res;
    }


    int fun(string s)
    {
        int res = 0;
        set<char> charSet;
        int i = 0, j = 0;
        while (i < s.size() && j < s.size())
        {
            // 不重复字符加入集合
            if (charSet.count(s[j]) == 0)
            {
                charSet.insert(s[j++]);
                res = max(res, j - i);
            }
            else
            {
                // 把重复字符和重复字符之前的字符从集合删除
                charSet.erase(s[i++]);
            }
        }
        return res;
    }
};

}

#endif // N3_LONGEST_SUBSTRING_WITHOUT_REPEATING_CHARACTERS_H
