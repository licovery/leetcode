#ifndef N970_POWERFUL_INTEGERS_H
#define N970_POWERFUL_INTEGERS_H

#include "leetcode_common.h"

namespace n970
{

class Solution
{
public:
    vector<int> powerfulIntegers(int x, int y, int bound)
    {
        //考虑x,y等于1的情况
        set<int> powerfulNumber;
        for (int i = 0; pow(x, i) < bound ; i++)
        {

            for (int j = 0; pow(x, i) + pow(y, j) <= bound ; j++)
            {

                powerfulNumber.insert(pow(x, i) + pow(y, j));
                if (y == 1)
                {
                    break;
                }
            }
            if (x == 1)
            {
                break;
            }
        }
        return vector<int> (powerfulNumber.begin(), powerfulNumber.end());
    }
private:
    int pow(int n, int exp)
    {
        int res = 1;
        while (exp--)
        {
            res *= n;
        }
        return res;
    }
};

}

#endif // N970_POWERFUL_INTEGERS_H
