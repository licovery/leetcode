#ifndef N811_SUBDOMAIN_VISIT_COUNT_H
#define N811_SUBDOMAIN_VISIT_COUNT_H

#include <bits/stdc++.h>
using namespace std;

namespace n811
{

class Solution
{
public:
    vector<string> subdomainVisits(vector<string> &cpdomains)
    {
        vector<string> res;
        map<string, int> subdomainVisitCount;
        for (const string &cpdomain : cpdomains)
        {
            int count = 0;
            vector<string> subdomains = parseSubdomain(cpdomain, count);
            for (const string &subdomain : subdomains)
            {
                subdomainVisitCount[subdomain] += count;
            }
        }

        for (auto it = subdomainVisitCount.begin(); it != subdomainVisitCount.end(); it++)
        {
            res.push_back(to_string(it->second) + ' ' + it->first);
        }
        return res;
    }

private:
    vector<string> parseSubdomain(string cpdomain, int &count)
    {

        string visitedCount;
        string domain;
        vector<string> subDomains;
        for (int i = 0; i < cpdomain.size(); i++)
        {
            if (cpdomain[i] == ' ')
            {
                visitedCount = cpdomain.substr(0, i);
                count = stoi(visitedCount);
                domain = cpdomain.substr(i + 1);
                domain += '.';
            }
        }
        // split
        int s = 0;
        for (int i = 0; i < domain.size(); i++)
        {
            if (domain[i] == '.')
            {
                string tmp = domain.substr(s, i - s);
                for (int j = 0; j < subDomains.size(); j++)
                {
                    subDomains[j] += '.';
                    subDomains[j] += tmp;
                }
                subDomains.push_back(tmp);
                s = i + 1;
            }
        }
        return subDomains;
    }
};

}

#endif // N811_SUBDOMAIN_VISIT_COUNT_H
