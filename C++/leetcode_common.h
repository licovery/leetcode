#ifndef LEETCODE_COMMON_H
#define LEETCODE_COMMON_H

#include <bits/stdc++.h>
using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Node
{
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val, vector<Node *> _children)
    {
        val = _val;
        children = _children;
    }
};


#endif // LEETCODE_COMMON_H
