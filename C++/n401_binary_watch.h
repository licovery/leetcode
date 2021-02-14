#ifndef N401_BINARY_WATCH_H
#define N401_BINARY_WATCH_H

#include <bits/stdc++.h>
using namespace std;

namespace n401
{

#define BINARY_MODULUS 2
#define HOUR_BINARY_LEN 4
#define MINUTE_BINARY_LEN 6
#define TIME_BINARY_LEN HOUR_BINARY_LEN + MINUTE_BINARY_LEN

class Solution
{
public:
    vector<string> readBinaryWatch(int num)
    {
        vector<string> result;
        bitset<TIME_BINARY_LEN> binaryHourMinute;
        dfs(binaryHourMinute, num, 0, 0, result);
        return result;
    }

private:
    void dfs(bitset<TIME_BINARY_LEN> &hourMinute, int num, int step, int numOfOne, vector<string> &result)
    {
        if (step >= hourMinute.size() || numOfOne >= num)
        {
            if (numOfOne == num)
            {
                for (; step < hourMinute.size(); step++)
                {
                    hourMinute[step] = 0;
                }
                addTimeToResult(hourMinute, result);
            }

            return;
        }

        for (auto bitValue = 0; bitValue < BINARY_MODULUS; bitValue++)
        {
            hourMinute[step] = bitValue;
            if (bitValue)
            {
                numOfOne++;
            }
            dfs(hourMinute, num, step + 1, numOfOne, result);
        }
    }

    void addTimeToResult(const bitset<TIME_BINARY_LEN> &hourMinute, vector<string> &result)
    {
        string timeStr = hourMinute.to_string();
        string hourStr = timeStr.substr(0, HOUR_BINARY_LEN);
        string minuteStr = timeStr.substr(HOUR_BINARY_LEN, MINUTE_BINARY_LEN);
        int hour = bitset<HOUR_BINARY_LEN> (hourStr).to_ulong();
        int minute = bitset<MINUTE_BINARY_LEN> (minuteStr).to_ulong();
        if (hour > 11 || minute > 59)
        {
            return;
        }
        string time;
        time += to_string(hour);
        time += ":";
        time += minute < 10 ? "0" + to_string(minute) : to_string(minute);
        result.push_back(time);
    }

};

}

#endif // N401_BINARY_WATCH_H
