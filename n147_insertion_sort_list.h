#ifndef N147_INSERTION_SORT_LIST_H
#define N147_INSERTION_SORT_LIST_H

#include "bits/stdc++.h"
using namespace std;


namespace n147
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
    ListNode *insertionSortList(ListNode *head)
    {
        ListNode headNode(0); //特殊节点，val无意义

        while (head)
        {
            ListNode *node = head;
            head = head->next;

            ListNode *insert = &headNode;
            while (insert && insert->next && node->val > insert->next->val)
            {
                insert = insert->next;
            }
            node->next = insert->next;
            insert->next = node;

        }
        return headNode.next;
    }
};

}

#endif // N147_INSERTION_SORT_LIST_H
