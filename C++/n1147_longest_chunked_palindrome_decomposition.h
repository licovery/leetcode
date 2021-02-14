#include "leetcode_common.h"

namespace n1147
{

class Solution
{
public:
    int longestDecomposition(string text)
    {
        int res = 0;
        int s = 0;
        int e = text.size();
        while (s < e)
        {
            int chunkLen = 1;
            while (2 * chunkLen <= e - s &&
                   text.substr(s, chunkLen) != text.substr(e - chunkLen, chunkLen))
            {
                chunkLen++;
            }

            if (2 * chunkLen <= e - s) // find chunked palindrome
            {
                s += chunkLen;
                e -= chunkLen;
                res += 2;
            }
            else
            {
                res += 1;
                break;
            }
        }
        return res;
    }
};

} // namespace n1147