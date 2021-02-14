#ifndef N148_SORT_LIST_H
#define N148_SORT_LIST_H

#include "bits/stdc++.h"
using namespace std;


namespace n148
{

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

//链表的自底向上归并排序，空间复杂度为 O(0)

class Solution
{
public:
    ListNode *sortList(ListNode *head)
    {
        ListNode headNode(0);
        headNode.next = head;

        int size = 0; //链表长度
        while (head)
        {
            head = head->next;
            size++;
        }

        for (int mergeLen = 1; mergeLen < size; mergeLen *= 2)
        {

            ListNode *tail = &headNode; //上一个末尾元素，tail->next指向当前需要处理元素

            while (tail->next) //还有元素没处理
            {
                ListNode *list1 = tail->next; //list1保证非空
                // 截断
                ListNode *list2 = trancate(list1, mergeLen);
                ListNode *nextMerge = trancate(list2, mergeLen); //下次merge开始时的node，会赋值给下次循环的list1

                // 进行排序
                tail = merge(list1, list2, tail);
                //拼接回来
                tail->next = nextMerge;
            }
        }

        return headNode.next;
    }
private:
    // list1与list2不同时为空，lastTail非空，返回值肯定非空
    // 将list1,list2拍好序后，插入lastTail中，返回排序后最后一个元素
    ListNode *merge(ListNode *list1, ListNode *list2, ListNode *lastTail)
    {
        ListNode *node = lastTail;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                node->next = list1;
                node = node->next;
                list1 = list1->next;
            }
            else
            {
                node->next = list2;
                node = node->next;
                list2 = list2->next;
            }
        }

        if (list1)
        {
            node->next = list1;
        }
        if (list2)
        {
            node->next = list2;
        }

        while (node->next)
        {
            node = node->next;
        }

        return node;
    }

    // 根据size（尽可能地）截断list，并返回截断后list末尾元素（在原始list中）的下一个元素
    ListNode *trancate(ListNode *head, int size)
    {
        if (head == nullptr)
        {
            return nullptr;
        }

        ListNode *tailNext = nullptr;
        ListNode *node = head;
        for (int i = 1; i < size  && node->next; i++)
        {
            node = node->next;
        }
        // node是list的末尾
        tailNext = node->next;
        node->next = nullptr; // 截断list
        return tailNext;
    }
};


// 自顶向下归并排序，由于使用的递归，其实空间复杂度已经为o(n)，递归本身就是消耗空间
class Solution1
{
public:
    ListNode *sortList(ListNode *head)
    {
        if (head == nullptr || head->next == nullptr)
        {
            return head;
        }

        ListNode header(0);
        header.next = head;

        ListNode *slow = &header, *fast = &header;

        while (slow->next && fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = slow->next;
        slow->next = nullptr;//截断
        slow = fast;

        ListNode *left = sortList(head);
        ListNode *right = sortList(slow);

        return merge(left, right);
    }
private:
    ListNode *merge(ListNode *list1, ListNode *list2)
    {
        ListNode headNode(0);
        ListNode *node = &headNode;

        while (list1 && list2)
        {
            if (list1->val <= list2->val)
            {
                node->next = list1;
                node = node->next;
                list1 = list1->next;
            }
            else
            {
                node->next = list2;
                node = node->next;
                list2 = list2->next;
            }
        }

        if (list1)
        {
            node->next = list1;
        }
        if (list2)
        {
            node->next = list2;
        }

        return headNode.next;
    }
};



}
#endif // N148_SORT_LIST_H
