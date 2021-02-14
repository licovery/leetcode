#ifndef N206_REVERSE_LINKED_LIST_H
#define N206_REVERSE_LINKED_LIST_H

#include "bits/stdc++.h"
using namespace std;

namespace n206
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
    ListNode * reverseList(ListNode *head)
    {
        ListNode listHeader(0);

        while (head)
        {
            ListNode *insertNode = head;
            head = head->next;
            insertNode->next = listHeader.next;
            listHeader.next = insertNode;
        }

        return listHeader.next;
    }
};

}

#endif // N206_REVERSE_LINKED_LIST_H
