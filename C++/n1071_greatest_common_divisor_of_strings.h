#include "leetcode_common.h"

namespace n1071
{

class Solution
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        string res;
        for (int i = 0; i < str1.size() && i < str2.size(); i++)
        {
            if (str1[i] != str2[i])
            {
                break;
            }
            string divisor = str1.substr(0, i + 1);
            if (isDivisor(str1, divisor) && isDivisor(str2, divisor))
            {
                res = divisor;
            }
        }
        return res;
    }

private:
    bool isDivisor(string str, string divisor)
    {
        if (str.size() % divisor.size() != 0)
        {
            return false;
        }

        for (int i = 0; i < str.size(); i += divisor.size())
        {
            if (str.substr(i, divisor.size()) != divisor)
            {
                return false;
            }
        }
        return true;
    }
};

class Solution2
{
public:
    string gcdOfStrings(string str1, string str2)
    {
        if (str1.size() < str2.size())
        {
            return gcdOfStrings(str2, str1);
        }

        if (str2.empty())
        {
            return str1;
        }

        if (str1.substr(0, str2.size()) != str2)
        {
            return "";
        }

        return gcdOfStrings(str1.substr(str2.size()), str2);
    }
};

} // namespace n1071