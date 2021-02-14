#ifndef N849_MAXIMIZE_DISTANCE_TO_CLOSEST_PERSON_H
#define N849_MAXIMIZE_DISTANCE_TO_CLOSEST_PERSON_H

#include <bits/stdc++.h>
using namespace std;

namespace n849
{

class Solution
{
public:
    int maxDistToClosest(vector<int> &seats)
    {
        int res = 0;
        int lastSittingSeat = 0;

        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                lastSittingSeat = i;
                break;
            }
        }

        if (seats[0] == 0)
        {
            res = max(res, lastSittingSeat - 0);
        }

        for (int i = lastSittingSeat + 1; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                res = max(res, (i - lastSittingSeat) / 2);
                lastSittingSeat = i;
            }

        }
        if (seats[seats.size() - 1] == 0)
        {
            res = max(res, (static_cast<int>(seats.size() - 1) - lastSittingSeat));
        }
        return  res;
    }



    int maxDistToClosest1(vector<int> &seats)
    {
        vector<int> sitting; //at least one person sitting
        for (int i = 0; i < seats.size(); i++)
        {
            if (seats[i] == 1)
            {
                sitting.push_back(i);
            }
        }

        int res = 0;

        if (seats[0] == 0)
        {
            int distanceSitFirst = sitting[0] - 0;
            res = max(res, distanceSitFirst);
        }
        if (seats[seats.size() - 1] == 0)
        {
            int distanceSitLast = (seats.size() - 1) - sitting[sitting.size() - 1];
            res = max(res, distanceSitLast);
        }

        for (int i = 0; i + 1 < sitting.size(); i++)
        {
            res = max(res, (sitting[i + 1] - sitting[i]) / 2);
        }
        return res;
    }
};

}

#endif // N849_MAXIMIZE_DISTANCE_TO_CLOSEST_PERSON_H
