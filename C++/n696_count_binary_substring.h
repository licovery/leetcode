#ifndef N696_COUNT_BINARY_SUBSTRING_H
#define N696_COUNT_BINARY_SUBSTRING_H

#include <bits/stdc++.h>
using namespace std;

namespace n696
{

class Solution
{
public:
    int countBinarySubstrings(const string &s) const
    {
        if (s.size() == 0)
        {
            return 0;
        }
        vector<int> contiguous;
        contiguous.push_back(1); //一个s[0]
        for (int i = 1; i < s.size(); i++)
        {
            if (s[i] == s[i - 1])
            {
                (*contiguous.rbegin())++; //逆向迭代器
            }
            else
            {
                contiguous.push_back(1);
            }
        }
        int count = 0;
        for (int i = 0; i + 1 < contiguous.size(); i++)
        {
            count += min(contiguous[i], contiguous[i + 1]);
        }
        return count;
    }
};


#define OK 0
#define TRY 1
#define ERROR 2

class Solution1
{
public:
    int countBinarySubstrings(const string &s) const
    {
        int count = 0;
        for (int i = 0; i < s.size(); i++)
        {
            SubStringDFA dfa(s[i]);
            for (int j = i + 1; j < s.size(); j++)
            {
                int status = dfa.add(s[j]);
                if (status == OK)
                {
                    int halfLen = (j - i + 1) / 2;
                    count += halfLen;//找到一个大的子串,其中肯定包含很多小的子串例如 000111 包含 0011 01，包含个数等于长度一半
                    i += halfLen - 1;
                    break;
                }
                else if (status == ERROR)
                {
                    break;
                }
            }
        }
        return count;
    }
private:
    //状态机判断子串是否符合匹配
    class SubStringDFA
    {
    public:
        SubStringDFA(char c): flag(0), first(c), last(c), uncontiguous(false)
        {
            flag++;
        }

        int add(char c)
        {
            if (last != c)
            {
                if (uncontiguous == false)
                {
                    uncontiguous = true;
                    last = c;
                }
                else
                {
                    return ERROR;
                }
            }

            if (c == first)
            {
                flag++;
            }
            else
            {
                flag--;
            }

            if (flag == 0)
            {
                return OK;
            }
            else if (flag < 0)
            {
                return ERROR;
            }
            else
            {
                return TRY;
            }
        }
    private:
        int flag;
        char first;
        char last;//上一个
        bool uncontiguous;
    };
};

}

#endif // N696_COUNT_BINARY_SUBSTRING_H
