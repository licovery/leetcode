#ifndef N2_ADD_TWO_NUMBER_H
#define N2_ADD_TWO_NUMBER_H

#include <bits/stdc++.h>
using namespace std;

namespace n2
{

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
    {
        ListNode head(0);
        ListNode *cur = &head;
        int carry = 0;
        while (l1 || l2)
        {
            int v1 = l1 ? l1->val : 0;
            int v2 = l2 ? l2->val : 0;
            int v = (v1 + v2 + carry) % 10;
            carry = (v1 + v2 + carry) / 10;

            cur->next = new ListNode(v);
            cur = cur->next;

            if (l1)
            {
                l1 = l1->next;
            }
            if (l2)
            {
                l2 = l2->next;
            }
        }
        // 最后处理进位
        if (carry)
        {
            cur->next = new ListNode(carry);
        }

        return head.next;
    }
};

}

#endif // N2_ADD_TWO_NUMBER_H
