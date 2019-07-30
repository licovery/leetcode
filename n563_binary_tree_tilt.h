#ifndef N563_BINARY_TREE_TILT_H
#define N563_BINARY_TREE_TILT_H

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
    int findTilt(TreeNode *root)
    {
        traverseSum(root);
        return totalTilt;
    }

    int traverseSum(TreeNode *root)
    {
        if (root == nullptr)
        {
            return 0;
        }
        int leftSum = traverseSum(root->left);
        int rightSum = traverseSum(root->right);
        totalTilt += abs(leftSum - rightSum);
        return root->val + leftSum + rightSum;
    }
private:
    int totalTilt = 0;
};

};

#endif // N563_BINARY_TREE_TILT_H
