#ifndef N897_INCREASING_ORDER_SEARCH_TREE_H
#define N897_INCREASING_ORDER_SEARCH_TREE_H

#include <bits/stdc++.h>
using namespace std;

namespace n897
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
    TreeNode *increasingBST(TreeNode *root)
    {
        inOrder(root);
        return res;
    }
private:
    TreeNode *node = nullptr;
    TreeNode *res = nullptr;

    void inOrder(TreeNode *root)
    {
        if (root == nullptr) return;

        inOrder(root->left);
        if (node == nullptr && res == nullptr)
        {
            res = node = root;
        }
        else
        {
            node->right = root;
            node->left = nullptr;
            node = root;
        }
        inOrder(root->right);
    }
};

}

#endif // N897_INCREASING_ORDER_SEARCH_TREE_H
