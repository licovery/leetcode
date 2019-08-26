#ifndef N669_TRIM_A_BINARY_SEARCH_TREE_H
#define N669_TRIM_A_BINARY_SEARCH_TREE_H

#include<bits/stdc++.h>

namespace n563
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
    TreeNode *trimBST(TreeNode *root, int L, int R)
    {
        if (!root)
        {
            return nullptr;
        }

        TreeNode *trimedTree = nullptr;

        if (root->val < L)
        {
            trimedTree = trimBST(root->right, L, R);
        }
        else if (root->val > R)
        {
            trimedTree = trimBST(root->left, L, R);
        }
        else
        {
            root->left = trimBST(root->left, L, R);
            root->right = trimBST(root->right, L, R);
            trimedTree = root;
        }
        return trimedTree;
    }
};

}

#endif // N669_TRIM_A_BINARY_SEARCH_TREE_H
