#ifndef N589_NARY_TREE_PREORDER_TRAVERSAL_H
#define N589_NARY_TREE_PREORDER_TRAVERSAL_H

#include "leetcode_common.h"

namespace n589
{

class Solution
{
public:
    vector<int> preorder(Node *root)
    {
        if (root == nullptr)
        {
            return result;
        }
        result.push_back(root->val);
        for (Node *node : root->children)
        {
            preorder(node);
        }
        return result;
    }
private:
    vector<int> result;
};

};

#endif // N589_NARY_TREE_PREORDER_TRAVERSAL_H
