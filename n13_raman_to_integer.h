#ifndef N13_RAMAN_TO_INTEGER_H
#define N13_RAMAN_TO_INTEGER_H

#include "bits/stdc++.h"
using namespace std;


namespace n13
{

class Solution
{
public:
    int romanToInt(string s)
    {
        int decDigit = 0;
        for (int i = 0; i < s.size(); i++)
        {
            if (i + 1 < s.size() && romanValue(s[i]) < romanValue(s[i + 1]))
            {
                decDigit -= romanValue(s[i]);
            }
            else
            {
                decDigit += romanValue(s[i]);
            }
        }
        return decDigit;
    }

private:
    int romanValue(char c)
    {
        map<char, int> value;
        value['I'] = 1;
        value['V'] = 5;
        value['X'] = 10;
        value['L'] = 50;
        value['C'] = 100;
        value['D'] = 500;
        value['M'] = 1000;
        return value[c];
    }
};


}

#endif // N13_RAMAN_TO_INTEGER_H
