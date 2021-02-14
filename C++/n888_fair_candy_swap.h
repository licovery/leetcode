#ifndef N888_FAIR_CANDY_SWAP_H
#define N888_FAIR_CANDY_SWAP_H

#include<bits/stdc++.h>
using namespace std;

namespace n888
{

class Solution
{
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B)
    {

        int sumA = 0;
        int sumB = 0;

        for (int i = 0; i < A.size(); i++)
        {
            sumA += A[i];
        }

        for (int i = 0; i < B.size(); i++)
        {
            sumB += B[i];
        }

        int fairSum = (sumA + sumB) / 2;


        sort(B.begin(), B.end());

        for (int i : A)
        {
            int target = fairSum - sumA + i;
            if (binary_search(B.begin(), B.end(), target))
            {
                return {i, target};
            }
        }
        return {};
    }
private:
    bool myBinarySearch(vector<int> a, int s, int e, int target)
    {
        while (s <= e)
        {
            int mid = (s + e) / 2;
            if (a[mid] == target)
            {
                return true;
            }
            else if (a[mid] < target)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return false;
    }
};

}

#endif // N888_FAIR_CANDY_SWAP_H
