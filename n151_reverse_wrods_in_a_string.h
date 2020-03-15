#ifndef N151_REVERSE_WRODS_IN_A_STRING_H
#define N151_REVERSE_WRODS_IN_A_STRING_H

#include "bits/stdc++.h"
using namespace std;


namespace n151
{

class Solution
{
public:
    string reverseWords(string s)
    {
        string res;
        istringstream in(s);
        string word;

        while (in >> word)
        {
            res = " " + word + res;
        }

        if (res.size() != 0)
        {
            res = res.substr(1);
        }
        return res;
    }
};


// 先把整个字符串反转，再把wrod反转，空间复杂度O(1)
class Solution2
{
public:
    string reverseWords(string s)
    {
        reverse(s.begin(), s.end());

        int fast = 0, slow = 0;
        // 这个for循环也是字符串分割的一种方法
        for (; fast < s.size(); fast++)
        {
            // 遇到一个新的word
            if (s[fast] != ' ')
            {
                // 如果不是第一个word就加上空格分割符
                if (slow != 0)
                {
                    s[slow++] = ' ';
                }
                int begin = slow;
                //读取完所有连续的字符
                while (s[fast] != ' ' && fast < s.size())
                {
                    s[slow++] = s[fast++];
                }
                reverse(s.begin() + begin, s.begin() + slow);
            }
        }

        return s.substr(0, slow);
    }
};


}

#endif // N151_REVERSE_WRODS_IN_A_STRING_H
