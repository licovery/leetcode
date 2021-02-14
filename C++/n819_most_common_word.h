#ifndef N819_MOST_COMMON_WORD_H
#define N819_MOST_COMMON_WORD_H

#include <bits/stdc++.h>
using namespace std;

namespace n819
{

class Solution
{
public:
    string mostCommonWord(string paragraph, vector<string> banned)
    {
        for (int i = 0; i < paragraph.size(); i++)
        {
            if (isalpha(paragraph[i]))
            {
                paragraph[i] = tolower(paragraph[i]);
            }
            else
            {
                paragraph[i] = ' ';
            }
        }

        vector<string> words = splitByChar(paragraph, ' ');

        map<string, int> countWords;
        for (string word : words)
        {
            countWords[word]++;
        }

        for (string banStr : banned)
        {
            countWords.erase(banStr);
        }

        string res;
        int occur = 0;
        for (auto it = countWords.begin(); it != countWords.end(); it++)
        {
            if (it->second > occur)
            {
                occur = it->second;
                res = it->first;
            }
        }
        return res;
    }

private:
    vector<string> splitByChar(string paragraph, char splitChar)
    {
        paragraph += splitChar; //方便分割，保证最后肯定以splitChar结尾
        vector<string> res;
        for (int start = 0, i = 0; i < paragraph.size(); i++)
        {
            if (paragraph[i] != splitChar && paragraph[start] == splitChar) //遇到非分割字符，并且没有开始匹配
            {
                start = i;//start置于开始匹配状态，即str[start]为非分割字符
            }

            if (paragraph[i] == splitChar && paragraph[start] != splitChar) //遇到分割字符，并且已经开始匹配了
            {
                res.push_back(paragraph.substr(start, i - start)); //匹配结束
                start = i; // start置回未匹配状态，即str[start]为分割字符
            }
        }
        return res;
    }
};

}

#endif // N819_MOST_COMMON_WORD_H
