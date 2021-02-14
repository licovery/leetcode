#ifndef N836_RECTANGLE_OVERLAP_H
#define N836_RECTANGLE_OVERLAP_H

#include <bits/stdc++.h>
using namespace std;

namespace n836
{

class Solution
{
//    A rectangle is represented as a list [x1, y1, x2, y2]
public:
    bool isRectangleOverlap(vector<int> &rec1, vector<int> &rec2)
    {
        return isIntervalOverlap(rec1[0], rec1[2], rec2[0], rec2[2]) &&
               isIntervalOverlap(rec1[1], rec1[3], rec2[1], rec2[3]);

    }
private:
    bool isIntervalOverlap(int start1, int end1, int start2, int end2)
    {
        // 逆向判断
        if (end2 <= start1 || start2 >= end1)
        {
            return false;
        }
        return true;
    }
};

}

#endif // N836_RECTANGLE_OVERLAP_H
