#ifndef N589_NARY_TREE_PREORDER_TRAVERSAL_H
#define N589_NARY_TREE_PREORDER_TRAVERSAL_H

#include<bits/stdc++.h>
using namespace std;

namespace n589
{

// Definition for a Node.
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

class Solution
{
public:
    vector<int> preorder(Node *root)
    {

    }
};

};

#endif // N589_NARY_TREE_PREORDER_TRAVERSAL_H
