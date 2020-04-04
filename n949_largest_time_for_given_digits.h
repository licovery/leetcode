#ifndef N949_LARGEST_TIME_FOR_GIVEN_DIGITS_H
#define N949_LARGEST_TIME_FOR_GIVEN_DIGITS_H

#include "leetcode_common.h"

namespace n949
{

class Solution
{
public:
    string largestTimeFromDigits(vector<int> &A)
    {
        time = A;
        arrangement(0);
        if (res == -1)
        {
            return "";
        }
        return toStr(res);
    }
private:
    void arrangement(int step)
    {
        if (step == time.size())
        {
            int tmp = toInt(time);
            if (tmp / 100 <= 23 && tmp % 100 <= 59 && tmp > res)
            {
                res = tmp;
            }
        }

        for (int i = step; i < time.size(); i++)
        {
            swap(time[i], time[step]);
            arrangement(step + 1);
            swap(time[i], time[step]);
        }
    }

    int toInt(const vector<int> vec)
    {
        return vec[0] * 1000 + vec[1] * 100 + vec[2] * 10 + vec[3];
    }

    string toStr(int time)
    {
        string res;

        res += to_string(time / 1000);
        time %= 1000;

        res +=  to_string(time / 100);
        time %= 100;

        res += ":";

        res += to_string(time / 10);
        time %= 10;

        res += to_string(time);

        return res;
    }

    vector<int> time;
    int res = -1;
};

}

#endif // N949_LARGEST_TIME_FOR_GIVEN_DIGITS_H
