#ifndef N242_VALID_ANAGRAM_H
#define N242_VALID_ANAGRAM_H

#include "bits/stdc++.h"
using namespace std;

namespace n242
{

class Solution
{
public:
    bool isAnagram(string s, string t)
    {
        if (s.size() != t.size())
        {
            return false;
        }

        vector<int> countChar1(26, 0);
        vector<int> countChar2(26, 0);
        for (auto i = 0; i < s.size(); i++)
        {
            countChar1[s[i] - 'a']++;
            countChar2[t[i] - 'a']++;
        }
        return countChar1 == countChar2;
    }
};

}

#endif // N242_VALID_ANAGRAM_H
