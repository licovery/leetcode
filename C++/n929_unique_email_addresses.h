#ifndef N929_UNIQUE_EMAIL_ADDRESSES_H
#define N929_UNIQUE_EMAIL_ADDRESSES_H

#include "leetcode_common.h"

namespace n929
{

class Solution
{
public:
    int numUniqueEmails(vector<string> &emails)
    {
        set<string> emailSet;
        for (auto str : emails)
        {
            emailSet.insert(realEmailAddr(str));
        }
        return emailSet.size();
    }
    string realEmailAddr(string email)
    {
        int pos = email.find('@');
        string localName = email.substr(0, pos);
        string domainName = email.substr(pos + 1);
        string realLoaclName;
        for (int i = 0; i < localName.size(); i++)
        {
            if (localName[i] == '+')
            {
                break;
            }
            else if (localName[i] == '.')
            {
                continue;
            }
            realLoaclName += localName[i];
        }
        return realLoaclName + '@' + domainName;
    }
};

}

#endif // N929_UNIQUE_EMAIL_ADDRESSES_H
