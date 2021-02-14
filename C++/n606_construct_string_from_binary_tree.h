#ifndef N606_CONSTRUCT_STRING_FROM_BINARY_TREE_H
#define N606_CONSTRUCT_STRING_FROM_BINARY_TREE_H

#include <bits/stdc++.h>
using namespace std;

namespace n606
{

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution
{
public:
    string tree2str(TreeNode *t)
    {
        if (t == nullptr)
        {
            return "";
        }

        tree += to_string(t->val);

        if (t->left)
        {
            tree += "(";
            tree2str(t->left);
            tree += ")";
        }

        if (t->right)
        {
            if (t->left == nullptr)
            {
                tree += "()";
            }
            tree += "(";
            tree2str(t->right);
            tree += ")";
        }
        return tree;
    }
private:
    string tree;
};

};

#endif // N606_CONSTRUCT_STRING_FROM_BINARY_TREE_H
