#include "leetcode_common.h"

namespace n43
{

class Solution
{
public:
    string multiply(const string &num1, const string &num2)
    {
        if (num1.size() == 0 || num2.size() == 0)
        {
            return "";
        }

        string ans;
        for (int i = 0; i < num2.size(); i++)
        {
            string tmp = multiplyChar(num1, num2[num2.size() - 1 - i]);
            if (i && tmp != "0")
            {
                tmp += string(i, '0');
            }
            ans = addStrings(ans, tmp);
        }
        return ans;
    }

private:
    string multiplyChar(const string &num1, char num2)
    {
        if (num1 == "0" || num2 == '0')
        {
            return "0";
        }

        int n2 = num2 - '0';
        string ans;
        int i = num1.size() - 1;
        int carry = 0;
        while (i >= 0 || carry)
        {
            int product = 0;
            if (i >= 0)
            {
                product += (num1[i--] - '0') * n2;
            }
            product += carry;
            carry = product / 10;
            product = product % 10;
            ans = static_cast<char>(product + '0') + ans;
        }
        return ans;
    }

    string addStrings(const string &num1, const string &num2)
    {
        int i = num1.size() - 1;
        int j = num2.size() - 1;
        int carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry)
        {
            int sum = 0;
            if (i >= 0)
                sum += num1[i--] - '0';
            if (j >= 0)
                sum += num2[j--] - '0';
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ans = static_cast<char>(sum + '0') + ans;
        }
        return ans;
    }
};

class Solution2
{
public:
    string multiply(const string &num1, const string &num2)
    {
        if (num1.size() == 0 || num2.size() == 0)
        {
            return "";
        }

        string ans(num1.size() + num2.size(), '0');

        for (int i = num1.size() - 1; i >= 0; i--)
        {
            int carry = 0;
            for (int j = num2.size() - 1; j >= 0; j--)
            {
                int tmp = (ans[i + j + 1] - '0') + (num1[i] - '0') * (num2[j] - '0') + carry;
                carry = tmp / 10;
                ans[i + j + 1] = (tmp % 10) + '0';
            }
            ans[i] = carry + '0';
        }

        auto startPos = ans.find_first_not_of('0');
        if (startPos != string::npos)
        {
            return ans.substr(startPos);
        }
        return "0";
    }
};

} // namespace n43