#ifndef N884_UNCOMMON_WORDS_FROM_TWO_SENTENCES_H
#define N884_UNCOMMON_WORDS_FROM_TWO_SENTENCES_H

#include <bits/stdc++.h>
using namespace std;

namespace n884
{

class Solution
{
public:
    vector<string> uncommonFromSentences(string A, string B)
    {
        vector<string> res;

        map<string, int> countWord;
        for (auto s : split(A))
        {
            countWord[s]++;
        }
        for (auto s : split(B))
        {
            countWord[s]++;
        }

        for (auto it = countWord.begin(); it != countWord.end(); it++)
        {
            if (it->second == 1)
            {
                res.push_back(it->first);
            }
        }

        return res;
    }
private:
    vector<string> split(const string &str, char separated = ' ')
    {
        vector<string> res;
        int last = 0;
        int cur = 0;
        for (; cur < str.size(); cur++)
        {
            if (str[last] == separated && str[cur] != separated)
            {
                last = cur;
            }
            if (str[last] != separated && str[cur] == separated)
            {
                res.push_back(str.substr(last, cur - last));
                last = cur;
            }
        }
        if (str[str.size() - 1] != separated)
        {
            res.push_back(str.substr(last, cur - last));
        }
        return res;
    }
};

}

#endif // N884_UNCOMMON_WORDS_FROM_TWO_SENTENCES_H
