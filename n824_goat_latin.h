#ifndef N824_GOAT_LATIN_H
#define N824_GOAT_LATIN_H

#include <bits/stdc++.h>
using namespace std;

namespace n824
{

class Solution
{
public:
    string toGoatLatin(string S)
    {
        vector<string> words = splitBySpace(S);
        string res;
        for (int i = 0; i < words.size(); i++)
        {
            string tmp = words[i];
            if (!isVowel(tmp[0]))
            {
                tmp += tmp[0];
                tmp = tmp.substr(1);
            }
            tmp += "ma";
            tmp += string (i + 1, 'a');
            res += tmp;
            res += ' ';
        }
        return res.substr(0, res.size() - 1);

    }
private:
    vector<string> splitBySpace(string sentence)
    {
        sentence += ' ';
        vector<string> res;
        for (int start = 0, i = 0; i < sentence.size(); i++)
        {
            if (sentence[start] == ' ' && sentence[i] != ' ')
            {
                start = i;
            }
            if (sentence[start] != ' ' && sentence[i] == ' ')
            {
                res.push_back(sentence.substr(start, i - start));
                start = i;
            }
        }
        return res;
    }

    bool isVowel(char c)
    {
        return c == 'a' ||
               c == 'e' ||
               c == 'i' ||
               c == 'o' ||
               c == 'u' ||
               c == 'A' ||
               c == 'E' ||
               c == 'I' ||
               c == 'O' ||
               c == 'U';
    }
};

}

#endif // N824_GOAT_LATIN_H
