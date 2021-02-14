#ifndef N703_KTH_LARGEST_ELEMENT_IN_A_STREAM_H
#define N703_KTH_LARGEST_ELEMENT_IN_A_STREAM_H

#include <bits/stdc++.h>
using namespace std;

namespace n703
{

class KthLargest
{
public:
    KthLargest(int k, vector<int> nums): _k(k), _minHeap(nums.begin(), nums.end())
    {
//        // 从空堆开始构建，较为低效
//        for (int i = 0; i < nums.size(); i++)
//        {
//            _minHeap.push(nums[i]);
//            if (_minHeap.size() > k)
//            {
//                _minHeap.pop();
//            }
//        }

        //另外一个更加高效的方法是自底向上建堆，复杂度O(n)
        //priority_queue的range initialization constructor就使用了这种办法
        while (_minHeap.size() > k)
        {
            _minHeap.pop();
        }
    }

    int add(int val)
    {
        _minHeap.push(val);
        if (_minHeap.size() > _k)
        {
            _minHeap.pop();
        }
        assert(_minHeap.size() == _k);
        return _minHeap.top();
    }
private:
    int _k;
    priority_queue<int, vector<int>, greater<int>> _minHeap; //Compare使用greater<int>，构造出来的是小顶堆
};

}

#endif // N703_KTH_LARGEST_ELEMENT_IN_A_STREAM_H
