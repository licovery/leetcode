#ifndef N5_LONGEST_PALINDROMIC_SUBSTRING_H
#define N5_LONGEST_PALINDROMIC_SUBSTRING_H

#include <bits/stdc++.h>
using namespace std;

namespace n5
{

class Solution
{
public:
    string longestPalindrome(string s)
    {
        string res;
        const int N = s.size();
        vector<vector<int>> dp(N, vector<int> (N, 0));
        for (int i = 0; i < N; i++)
        {
            dp[i][i] = 1;
            if (dp[i][i] > res.size())
            {
                res = s.substr(i, 1);
            }
        }

        //dp[i][j]依赖dp[i+1][j-1]
        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i < j; i++)
            {
                if (i + 1 == j) //长度为2
                {
                    dp[i][j] = s[i] == s[j] ? 2 : 0;
                }
                else
                {
                    //不能组成回文序列
                    if (dp[i + 1][j - 1] == 0 || s[i] != s[j])
                    {
                        dp[i][j] = 0;
                    }
                    else
                    {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                }

                if (dp[i][j] > res.size())
                {
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }

    //修改后的代码
    string solution(string s)
    {
        string res;
        const int N = s.size();
        vector<vector<bool>> P(N, vector<bool> (N, false)); //P[i][j] = true means Si...Sj is a palindrome

        for (int j = 0; j < N; j++)
        {
            for (int i = 0; i <= j; i++)
            {
                if (i == j)
                {
                    P[i][i] = true;
                }
                else if (i + 1 == j)
                {
                    P[i][j] = s[i] == s[j];
                }
                else
                {
                    P[i][j] = P[i + 1][j - 1] && s[i] == s[j];
                }
                if (P[i][j] && j - i + 1 > res.size())
                {
                    res = s.substr(i, j - i + 1);
                }
            }
        }
        return res;
    }
};

}

#endif // N5_LONGEST_PALINDROMIC_SUBSTRING_H
