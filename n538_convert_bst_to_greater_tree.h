#ifndef N538_CONVERT_BST_TO_GREATER_TREE_H
#define N538_CONVERT_BST_TO_GREATER_TREE_H

#include <bits/stdc++.h>
using namespace std;


namespace n538
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
    TreeNode *convertBST(TreeNode *root)
    {
        int greaterSum = 0;
        allGreaterNode(root, greaterSum);
        return root;
    }

//    greaterSum 记录全部 比node子树大 的节点的总和
    void allGreaterNode(TreeNode *node, int &greaterSum)
    {
        if (node == NULL)
        {
            return;
        }
        //遍历右子树，此时greaterSum就是比node大的所有节点的总和
        allGreaterNode(node->right, greaterSum);

        greaterSum += node->val;
        node->val = greaterSum;

        allGreaterNode(node->left, greaterSum);
    }
};

}

#endif // N538_CONVERT_BST_TO_GREATER_TREE_H
