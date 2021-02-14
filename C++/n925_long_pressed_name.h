#ifndef N925_LONG_PRESSED_NAME_H
#define N925_LONG_PRESSED_NAME_H

#include "leetcode_common.h"

namespace n925
{

class Solution
{
public:
    bool isLongPressedName(string name, string typed)
    {
        int i = 1;
        int j = 1;
        name = '#' + name + '#';
        typed = '#' + typed + '#';
        while (i < name.size() && j < typed.size())
        {
            if (name[i] == typed[j])
            {
                i++;
                j++;
            }
            else
            {
                if (typed[j] == name[i - 1])
                {
                    j++;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
};

}

#endif // N925_LONG_PRESSED_NAME_H
