#ifndef N806_NUMBER_OF_LINES_TO_WRITE_STRING_H
#define N806_NUMBER_OF_LINES_TO_WRITE_STRING_H

#include <bits/stdc++.h>
using namespace std;

namespace n806
{

class Solution
{
public:
    vector<int> numberOfLines(vector<int> &widths, string S)
    {
        int line = 1;
        int unit = 0;
        for (char letter : S)
        {
            int width = widths[letter - 'a'];
            // wirte to next line
            if (unit + width > MAX_UNIT_PER_LINE)
            {
                line++;
                unit = width;
            }
            else
            {
                unit += width;
            }
        }
        return vector<int> {line, unit};
    }
private:
    static constexpr int MAX_UNIT_PER_LINE = 100;
};

}

#endif // N806_NUMBER_OF_LINES_TO_WRITE_STRING_H
