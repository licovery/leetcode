#include "leetcode_common.h"

namespace n1005
{

class Solution
{
public:
    int largestSumAfterKNegations(vector<int> &A, int K)
    {
        sort(A.begin(), A.end());
        int total = 0;
        int negetive = 0; //记录负数的个数，前negetive个均为负数
        for (int n : A)
        {
            total += n;
            if (n < 0)
            {
                negetive++;
            }
        }

        int i = 0;
        while (i < negetive && K) // 尽可能把负数变成正数
        {
            A[i] = -A[i];
            total += 2 * A[i];
            i++;
            K--;
        }

        if (K > 0) // A内已经全部为正
        {
            if (K % 2 != 0) // K为奇数，K为偶数则无操作
            {
                total -= 2 * (*min_element(A.begin(), A.end())); //把最小的变为负数
            }
        }

        return total;
    }
};

} // namespace n1005